import numpy as np
import math

def calc_JC(y_true, y_pred):
    '''
    计算并返回JC系数
    :param y_true: 参考模型给出的簇，类型为ndarray
    :param y_pred: 聚类模型给出的簇，类型为ndarray
    :return: JC系数
    '''

    #******** Begin *******#
    yt = np.asarray(y_true)
    yp = np.asarray(y_pred)
    n = len(yt)

    a = b = c = d = 0
    for i in range(n):
        for j in range(i + 1, n):
            if yp[i] == yp[j] and yt[i] == yt[j]:
                a += 1
            elif yp[i] == yp[j] and yt[i] != yt[j]:
                b += 1
            elif yp[i] != yp[j] and yt[i] == yt[j]:
                c += 1
            else:
                d += 1

    den = a + b + c
    return 0.0 if den == 0 else a / den
    #******** End *******#


def calc_FM(y_true, y_pred):
    '''
    计算并返回FM指数
    :param y_true: 参考模型给出的簇，类型为ndarray
    :param y_pred: 聚类模型给出的簇，类型为ndarray
    :return: FM指数
    '''

    #******** Begin *******#
    yt = np.asarray(y_true)
    yp = np.asarray(y_pred)
    n = len(yt)

    a = b = c = d = 0
    for i in range(n):
        for j in range(i + 1, n):
            if yp[i] == yp[j] and yt[i] == yt[j]:
                a += 1
            elif yp[i] == yp[j] and yt[i] != yt[j]:
                b += 1
            elif yp[i] != yp[j] and yt[i] == yt[j]:
                c += 1
            else:
                d += 1

    den1 = a + b
    den2 = a + c
    if den1 == 0 or den2 == 0:
        return 0.0
    return float(math.sqrt((a / den1) * (a / den2)))
    #******** End *******#

def calc_Rand(y_true, y_pred):
    '''
    计算并返回Rand指数
    :param y_true: 参考模型给出的簇，类型为ndarray
    :param y_pred: 聚类模型给出的簇，类型为ndarray
    :return: Rand指数
    '''

    #******** Begin *******#
    yt = np.asarray(y_true)
    yp = np.asarray(y_pred)
    n = len(yt)

    a = b = c = d = 0
    for i in range(n):
        for j in range(i + 1, n):
            if yp[i] == yp[j] and yt[i] == yt[j]:
                a += 1
            elif yp[i] == yp[j] and yt[i] != yt[j]:
                b += 1
            elif yp[i] != yp[j] and yt[i] == yt[j]:
                c += 1
            else:
                d += 1

    tot = n * (n - 1) // 2
    return 0.0 if tot == 0 else (a + d) / tot
    #******** End *******#



