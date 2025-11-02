import numpy as np
import math

def calc_DBI(feature, pred):
    '''
    计算并返回DB指数
    :param feature: 待聚类数据的特征，类型为`ndarray`
    :param pred: 聚类后数据所对应的簇，类型为`ndarray`
    :return: DB指数
    '''

    #********* Begin *********#
    label_set = np.unique(pred)
    mu = {}
    label_count = {}
    for label in label_set:
        mu[label] = np.zeros([len(feature[0])])
        label_count[label] = 0
    for i in range(len(pred)):
        mu[pred[i]] += feature[i]
        label_count[pred[i]] += 1
    for key in mu.keys():
        mu[key] /= label_count[key]
    avg_d = {}
    for label in label_set:
        avg_d[label] = 0
    for i in range(len(pred)):
        avg_d[pred[i]] += np.sqrt(np.sum(np.square(feature[i] - mu[pred[i]])))
    for key in mu.keys():
        avg_d[key] /= label_count[key]
    cen_d = []
    for i in range(len(label_set)-1):
        t = {'c1':label_set[i], 'c2':label_set[i+1], 'dist':np.sqrt(np.sum(np.square(mu[label_set[i]] - mu[label_set[i+1]])))}
        cen_d.append(t)
    dbi = 0
    for k in range(len(label_set)):
        max_item = 0
        for i in range(len(label_set)):
            for j in range(i, len(label_set)):
                for p in range(len(cen_d)):
                    if cen_d[p]['c1'] == label_set[i] and cen_d[p]['c2'] == label_set[j]:
                        d = (avg_d[label_set[i]] + avg_d[label_set[j]])/cen_d[p]['dist']
                        if d > max_item:
                            max_item = d
        dbi += max_item
    dbi /= len(label_set)
    return dbi
    #********* End *********#


def calc_DI(feature, pred):
    '''
    计算并返回Dunn指数
    :param feature: 待聚类数据的特征，类型为`ndarray`
    :param pred: 聚类后数据所对应的簇，类型为`ndarray`
    :return: Dunn指数
    '''

    #********* Begin *********#
    label_set = np.unique(pred)
    min_d = []
    for i in range(len(label_set)-1):
        t = {'c1': label_set[i], 'c2': label_set[i+1], 'dist': np.inf}
        min_d.append(t)
    for i in range(len(feature)):
        for j in range(i, len(feature)):
            for p in range(len(min_d)):
                if min_d[p]['c1'] == pred[i] and min_d[p]['c2'] == pred[j]:
                    d = np.sqrt(np.sum(np.square(feature[i] - feature[j])))
                    if d < min_d[p]['dist']:
                        min_d[p]['dist'] = d
    max_diam = 0
    for i in range(len(feature)):
        for j in range(i, len(feature)):
            if pred[i] == pred[j]:
                d = np.sqrt(np.sum(np.square(feature[i] - feature[j])))
                if d > max_diam:
                    max_diam = d
    di = np.inf
    for i in range(len(label_set)):
        for j in range(i, len(label_set)):
            for p in range(len(min_d)):
                d = min_d[p]['dist']/max_diam
                if d < di:
                    di = d
    return d
    #********* End *********#
