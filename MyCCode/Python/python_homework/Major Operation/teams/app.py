from flask import Flask, render_template
import pandas as pd
import matplotlib
matplotlib.use('Agg')  # 用于服务器环境
import matplotlib.pyplot as plt
from io import BytesIO
import base64

app = Flask(__name__)

def create_plot():
    df = pd.read_csv('team_rankings.csv')
    # 创建可视化图表代码...
    img = BytesIO()
    plt.savefig(img, format='png')
    img.seek(0)
    return base64.b64encode(img.getvalue()).decode()

@app.route('/')
def dashboard():
    # 获取最新数据
    df = pd.read_csv('team_rankings.csv')
    latest = df[df['date'] == df['date'].max()]
    
    # 生成图表
    plot_url = create_plot()
    
    return render_template('dashboard.html',
                           tables=[latest.to_html(classes='data')],
                           plot_url=plot_url)

if __name__ == '__main__':
    app.run(debug=True)