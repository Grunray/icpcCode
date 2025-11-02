import matplotlib.pyplot as plt
import matplotlib.dates as mdates
from datetime import datetime
import numpy as np

# 设置中文字体
plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

# 全体任务数据（含负责人）
tasks = [
    {"name": "项目启动会议", "start": "2023-06-08", "end": "2023-06-09", "type": "会议", "owner": "全体"},
    {"name": "需求确认", "start": "2023-06-08", "end": "2023-06-09", "type": "规划", "owner": "付泊源"},
    {"name": "系统架构设计", "start": "2023-06-10", "end": "2023-06-12", "type": "设计", "owner": "高新博"},
    {"name": "UI原型设计", "start": "2023-06-10", "end": "2023-06-11", "type": "设计", "owner": "韩文星"},
    {"name": "环境搭建", "start": "2023-06-11", "end": "2023-06-12", "type": "配置", "owner": "高新博"},
    {"name": "用户管理开发", "start": "2023-06-13", "end": "2023-06-17", "type": "开发", "owner": "付泊源"},
    {"name": "资料管理开发", "start": "2023-06-18", "end": "2023-06-20", "type": "开发", "owner": "韩文星"},
    {"name": "智能分类开发", "start": "2023-06-19", "end": "2023-06-22", "type": "开发", "owner": "韩文星"},
    {"name": "API对接开发", "start": "2023-06-21", "end": "2023-06-23", "type": "集成", "owner": "付泊源"},
    {"name": "单元测试", "start": "2023-06-24", "end": "2023-06-25", "type": "测试", "owner": "高新博"},
    {"name": "集成测试", "start": "2023-06-26", "end": "2023-06-27", "type": "测试", "owner": "高新博"},
    {"name": "性能优化", "start": "2023-06-27", "end": "2023-06-27", "type": "优化", "owner": "高新博"},
    {"name": "用户手册编写", "start": "2023-06-28", "end": "2023-06-29", "type": "文档", "owner": "全体"},
    {"name": "系统部署", "start": "2023-06-29", "end": "2023-06-30", "type": "部署", "owner": "全体"},
    {"name": "验收测试", "start": "2023-06-30", "end": "2023-06-30", "type": "测试", "owner": "全体"}
]

# 转换日期格式
for task in tasks:
    task["start"] = datetime.strptime(task["start"], "%Y-%m-%d")
    task["end"] = datetime.strptime(task["end"], "%Y-%m-%d")

# 创建图形
fig, ax = plt.subplots(figsize=(14, 8))

# 颜色和样式设置
type_colors = {
    '会议': '#FF9999', '规划': '#FFCC99', '设计': '#66B3FF',
    '配置': '#99FF99', '开发': '#99FF99', '集成': '#FFD700',
    '测试': '#FF6666', '优化': '#FFB366', '文档': '#c2c2f0',
    '部署': '#ff99ff'
}

owner_markers = {
    '付泊源': 'o',
    '高新博': 's',
    '韩文星': '^',
    '全体': 'D'
}

# 绘制甘特图
for i, task in enumerate(tasks):
    duration = (task["end"] - task["start"]).days + 1
    bar = ax.barh(
        task["name"],
        width=duration,
        left=task["start"],
        height=0.6,
        color=type_colors[task["type"]],
        edgecolor='black',
        alpha=0.8
    )

    # 添加负责人标记（调整到条形右侧）
    x_pos = task["end"] - np.timedelta64(1, 'D') if duration > 1 else task["start"]
    ax.plot(
        x_pos, i,
        marker=owner_markers[task["owner"]],
        markersize=10,
        color='black',
        markeredgewidth=1,
        markerfacecolor='white'  # 空心标记
    )

    # 添加任务类型标签（调整到条形左侧）
    label_x = task["start"] + np.timedelta64(1, 'D') if duration > 2 else task["start"]
    ax.text(
        label_x, i,
        task["type"],
        ha='left',
        va='center',
        fontsize=9,
        bbox=dict(facecolor='white', alpha=0.7, edgecolor='none', pad=1)  # 添加白色背景
    )

# 设置坐标轴
ax.xaxis.set_major_locator(mdates.DayLocator())
ax.xaxis.set_major_formatter(mdates.DateFormatter("%m-%d"))
plt.xticks(rotation=45)
plt.gca().invert_yaxis()

# 添加标题和说明
plt.title("学习资料管理系统开发 - 全体任务甘特图", fontsize=16, pad=20)
plt.xlabel("日期", fontsize=12)
plt.ylabel("任务内容", fontsize=12)
plt.grid(axis='x', linestyle='--', alpha=0.5)

# 创建自定义图例
from matplotlib.patches import Patch

legend_elements = [
    *[Patch(facecolor=color, label=type_) for type_, color in type_colors.items()],
    *[plt.Line2D([0], [0], marker=marker, color='w', label=owner,
                 markerfacecolor='white', markeredgecolor='black', markersize=10)
      for owner, marker in owner_markers.items()]
]

ax.legend(
    handles=legend_elements,
    bbox_to_anchor=(1.25, 1),
    title="图例说明"
)

plt.tight_layout()
plt.savefig("全体任务甘特图_优化版.png", dpi=300, bbox_inches='tight')
plt.show()