from sklearn.metrics.cluster import fowlkes_mallows_score, adjusted_rand_score

def cluster_performance(y_true, y_pred):
    '''
    返回Rand指数和FM指数
    :param y_true:参考模型的簇划分，类型为`ndarray`
    :param y_pred:聚类模型给出的簇划分，类型为`ndarray`
    :return: Rand指数，FM指数
    '''

    #********* Begin *********#
    yt = list(y_true)
    yp = list(y_pred)
    fm = float(fowlkes_mallows_score(yt, yp))
    ari = float(adjusted_rand_score(yt, yp))
    return fm, ari
    #********* End *********#


