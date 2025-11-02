import pandas as pd
import matplotlib.pyplot as plt

def analyze_data(filename='team_rankings.csv'):
    df = pd.read_csv(filename)
    
    # 数据清洗
    df['date'] = pd.to_datetime(df['date'])
    df = df.sort_values(by='date')
    
    # 分析示例：各战队最新排名变化
    latest_date = df['date'].max()
    previous_date = df[df['date'] < latest_date]['date'].max()
    
    current = df[df['date'] == latest_date]
    previous = df[df['date'] == previous_date]
    
    merged = pd.merge(current, previous, on='team', suffixes=('_current', '_previous'))
    merged['change'] = merged['rank_previous'] - merged['rank_current']
    
    # 保存分析结果
    merged[['team', 'rank_current', 'change']].to_csv('rank_changes.csv', index=False)
    
    return merged

def visualize_data(df):
    # 创建可视化图表
    plt.figure(figsize=(15, 8))
    
    # 示例1：TOP10战队排名变化折线图
    top_teams = df.sort_values(by='rank_current').head(10)
    plt.subplot(2, 1, 1)
    for team in top_teams['team']:
        team_data = df[df['team'] == team]
        plt.plot(team_data['date'], team_data['rank'], label=team)
    plt.gca().invert_yaxis()
    plt.title('TOP10 Teams Ranking Trend')
    plt.xlabel('Date')
    plt.ylabel('Rank')
    plt.legend()
    
    # 示例2：排名变化分布饼图
    plt.subplot(2, 1, 2)
    changes = df['change'].apply(lambda x: '上升' if x>0 else ('下降' if x<0 else '持平'))
    changes.value_counts().plot.pie(autopct='%1.1f%%')
    plt.title('Rank Changes Distribution')
    
    plt.tight_layout()
    plt.savefig('rank_analysis.png')
    plt.show()

if __name__ == '__main__':
    analyzed_data = analyze_data()
    visualize_data(analyzed_data)