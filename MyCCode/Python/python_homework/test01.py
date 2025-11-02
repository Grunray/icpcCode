import matplotlib.pyplot as plt

# 数据
labels = ["Level1", "Level2", "Level3", "Level4"]
sizes = [35, 45, 15, 5]

plt.pie(sizes, labels=labels, autopct='%1.1f%%')
# plt.title("团队安全成熟度分布")
plt.axis('equal')
plt.show()