import requests
from bs4 import BeautifulSoup
import pandas as pd
import re
import sqlite3
from fake_useragent import UserAgent
from tenacity import retry, stop_after_attempt, wait_exponential
import random
import time

class HLTVScraper:
    def __init__(self):
        self.ua = UserAgent()
        self.db_conn = sqlite3.connect('hltv_top20.db')
        
    def __del__(self):
        self.db_conn.close()

    @retry(stop=stop_after_attempt(3), wait=wait_exponential(multiplier=1, min=2, max=10))
    def get_page(self, url):
        headers = {'User-Agent': self.ua.random}
        time.sleep(random.uniform(1, 3))  # 随机延迟
        
        response = requests.get(url, headers=headers)
        response.raise_for_status()
        return BeautifulSoup(response.content, 'html.parser')

    def parse_player_data(self, soup, year):
        players = []
        # 根据实际页面结构调整选择器
        entries = soup.select('.top-player')
        
        for entry in entries:
            try:
                rank = entry.select_one('.rank').text.strip()
                name = entry.select_one('.player-name').text.strip()
                rating = re.search(r'\d+\.\d+', entry.select_one('.rating').text).group()
                
                players.append({
                    'year': year,
                    'player': name,
                    'rank': int(rank),
                    'rating': float(rating)
                })
            except Exception as e:
                print(f"Error parsing entry: {e}")
        return players

    def scrape_year(self, year):
        url = f'https://www.hltv.org/news/{year}/hltv-top-20-players-of-{year}'
        try:
            soup = self.get_page(url)
            data = self.parse_player_data(soup, year)
            self.save_to_db(data)
            print(f"Successfully scraped {year}")
            return True
        except Exception as e:
            print(f"Failed to scrape {year}: {e}")
            return False

    def save_to_db(self, data):
        df = pd.DataFrame(data)
        df.to_sql('players', self.db_conn, if_exists='append', index=False)

    def run(self, start_year=2013, end_year=None):
        end_year = end_year or pd.Timestamp.now().year - 1
        for year in range(start_year, end_year + 1):
            self.scrape_year(year)

if __name__ == '__main__':
    scraper = HLTVScraper()
    scraper.run(2013, 2024)  # 抓取指定年份范围