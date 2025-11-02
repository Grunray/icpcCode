#encoding=utf8
from sklearn.cluster import DBSCAN
def data_cluster(data):
    '''
    input: data(ndarray) :数据
    output: result(ndarray):聚类结果
    '''
    #********* Begin *********#
    db=DBSCAN(eps=0.3,min_samples=5)
    result=db.fit_predict(data)
    return result
    #********* End *********#