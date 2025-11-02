from utils import generateRules
import pandas as pd

def genRules(data_path, min_support, min_conf):
    '''
    对文件路径为data_path的数据进行关联规则挖掘
    :param data_path: 数据集路径
    :param min_support: 最小支持度
    :param min_conf: 最小置信度
    :return:关联规则信息，类型为list
    '''
    # *********Begin*********#
    def T(x):
        m={'yogurt':1,'pork':2,'sandwich bags':3,'lunch meat':4,'all- purpose':5,'flour':6,'soda':7,'butter':8,'vegetables':9,'beef':10,'aluminum foil':11,'dinner rolls':12,'shampoo':13,'mixes':14,'soap':15,'laundry detergent':16,'ice cream':17,'toilet paper':18,'hand soap':19,'waffles':20,'cheeses':21,'milk':22,'dishwashing liquid/detergent':23,'individual meals':24,'cereals':25,'tortillas':26,'spaghetti sauce':27,'ketchup':28,'sandwich loaves':29,'poultry':30,'bagels':31,'eggs':32,'juice':33,'pasta':34,'paper towels':35,'coffee/tea':36,'fruits':37,'sugar':38}
        return m[x]
    def aprior_data(data):
        b=[]
        for id in data['id'].unique():
            a=[data['good'][i] for i,j in enumerate(data['id']) if j==id]
            b.append(a)
        return b
    d=pd.read_csv(data_path)
    d['good']=d['good'].apply(T)
    ds=aprior_data(d)
    rult=generateRules(ds,min_support,min_conf)
    return rult
    #*********End*********#
