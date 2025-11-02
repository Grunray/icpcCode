from pyecharts.charts import Map
from pyecharts import options as opts
import sqlite3
import json
import random

# 从数据库读取数据
conn = sqlite3.connect('china_areas.db')
cursor = conn.cursor()
cursor.execute('SELECT name, coordinates FROM areas')
rows = cursor.fetchall()

# 构造可视化数据
geo_json = {
    "type": "FeatureCollection",
    "features": []
}

visual_data = []
for row in rows:
    name, coordinates = row
    visual_data.append((name, random.randint(1, 100)))
    
    # 构造GeoJSON特征
    geo_json['features'].append({
        "type": "Feature",
        "properties": {"name": name},
        "geometry": {
            "type": "MultiPolygon",
            "coordinates": json.loads(coordinates)
        }
    })

# 生成地图
c = (
    Map()
    .add("区域示例", 
        visual_data, 
        #geo_json=geo_json,
        is_map_symbol_show=False)
    .set_global_opts(
        title_opts=opts.TitleOpts(title="中国行政区划图"),
        visualmap_opts=opts.VisualMapOpts(max_=100)
    )
)

c.render('china_map.html')
conn.close()