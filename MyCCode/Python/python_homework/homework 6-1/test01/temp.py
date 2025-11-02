import requests
import sqlite3
import json

# 爬取GeoJSON数据
url = 'https://geo.datav.aliyun.com/areas_v2/bound/100000_full.json'
response = requests.get(url)
data = response.json()

# 创建数据库和表
conn = sqlite3.connect('china_areas.db')
cursor = conn.cursor()
cursor.execute('''
    CREATE TABLE IF NOT EXISTS areas (
        adcode INTEGER PRIMARY KEY,
        name TEXT,
        parent_adcode INTEGER,
        geometry_type TEXT,
        coordinates TEXT
    )
''')

# 处理并存储数据
def process_features(features, parent_code=100000):
    provinces = []
    # 第一次遍历处理省份
    for feature in features:
        props = feature.get('properties', {})
        current_parent = props.get('parent', {}).get('adcode', 0)
        if current_parent == parent_code:
            adcode = props.get('adcode')
            name = props.get('name')
            geometry = feature.get('geometry', {})
            cursor.execute('''
                INSERT OR REPLACE INTO areas VALUES (?, ?, ?, ?, ?)''',
                (
                    adcode,
                    name,
                    current_parent,
                    geometry.get('type'),
                    json.dumps(geometry.get('coordinates'))
                ))
            provinces.append(adcode)
    
    # 第二次遍历处理城市
    for feature in features:
        props = feature.get('properties', {})
        current_parent = props.get('parent', {}).get('adcode', 0)
        if current_parent in provinces:
            adcode = props.get('adcode')
            name = props.get('name')
            geometry = feature.get('geometry', {})
            cursor.execute('''
                INSERT OR REPLACE INTO areas VALUES (?, ?, ?, ?, ?)
            ''', (
                adcode,
                name,
                current_parent,
                geometry.get('type'),
                json.dumps(geometry.get('coordinates'))
            ))

process_features(data['features'])
conn.commit()
conn.close()