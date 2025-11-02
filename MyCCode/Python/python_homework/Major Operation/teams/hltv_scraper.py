import requests
from bs4 import BeautifulSoup
import pandas as pd
import time
from datetime import datetime
import random

def get_team_rankings():
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36', 
        'cookie' : "MatchFilter={%22active%22:false%2C%22live%22:false%2C%22stars%22:1%2C%22lan%22:false%2C%22teams%22:[]}; CookieConsent={stamp:%274GHEo5LYkDlCLNiy1Q2jpeeXtu8JV1PrpjrnXHr9w1MRD6JmF/B3jA==%27%2Cnecessary:true%2Cpreferences:false%2Cstatistics:false%2Cmarketing:false%2Cmethod:%27explicit%27%2Cver:1%2Cutc:1734405069032%2Cregion:%27cn%27}; __cf_bm=qHMunDmYfkTSYch3f5kLRLI1RCK_c6jqeQCcJDV8HPo-1744075906-1.0.1.1-C6yo09EnAZeXCq2Cr6pwYEjsNx0WrchnX9SYo8_zL4kifGwm2DkwQQiQj4ltfmFTLWEGsHsxDWIxbRVkbSLWQ0pQlArYDDREeWY.FiBQ6G8; cf_clearance=faU.zRJ1Mo_o2nxDDS.LL4pm5B7CUbGBG8th9xwePK8-1744075909-1.2.1.1-2u7FHqaaDQz14Lx053_zD9OzROyHw9KSI0vAswsuKBcvmnKMUNL1KVn.CfpjjRvjDLwylqo5ayRIDk4l6OzwiCu_UCqTMDZGyJqBzSDAFyrhvuKWo5UjDaewSBuLH1CE_msP98N2QRGK4.ba4fZXmAkJBzE66IuIeXcFXwRkbYhDT1Oi5Elx0WpKzZJ_.r5.C4.I22yDNOpDLuc5V46ElwhI3kV9BqudUEzAi6pcKLQcQp2l2nqwnw41gvTHyVkuL3YJrLvxjDy1scQ82kABCJofQybukU_D4LoB23sN2CzfJL2LXbs.N7yhcZllULoM2merXXsYcPg2eyDTYk91RJlicD4Nvg00kW46Ub4Pp8M"
    }
    
    url = 'https://www.hltv.org/ranking/teams'
    
    try:
        time.sleep(random.uniform(1, 4))
        response = requests.get(url, headers=headers)
        response.raise_for_status()
        
        soup = BeautifulSoup(response.content, 'html.parser')
        rankings = []
        date = datetime.now().strftime('%Y-%m-%d')
        print("geting")
        # 解析排名数据（根据实际页面结构调整选择器）
        teams = soup.select('div.ranked-team')
        for team in teams:
            position = team.select_one('.position').text.strip()
            name = team.select_one('.name').text.strip()
            points = team.select_one('.points').text.strip().replace('(', '').replace(')', '')
            rankings.append({
                'date': date,
                'team': name,
                'rank': int(position),
                'points': int(points)
            })
            print("getting team{name}")
        return rankings
    
    except Exception as e:
        print(f"Error fetching data: {e}")
        return []

def save_to_csv(data, filename='team_rankings.csv'):
    df = pd.DataFrame(data)
    try:
        # 追加模式保存
        with open(filename, 'a') as f:
            df.to_csv(f, header=f.tell()==0, index=False)
        print(f"Data saved to {filename}")
    except Exception as e:
        print(f"Error saving data: {e}")

# if __name__ == '__main__':
print(1)

rankings = get_team_rankings()
print(1)
if rankings : 
    save_to_csv(rankings)
    print("<---Teams Rank Got Successful--->")
else :
    print("<---Teams Rank Got Failed--->")
    #time.sleep(86400)  # 每天执行一次