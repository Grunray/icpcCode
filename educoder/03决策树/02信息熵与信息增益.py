import numpy as np

# 计算信息熵
def calcInfoEntropy(feature, label):
    '''
    计算信息熵
    :param feature:数据集中的特征，类型为ndarray
    :param label:数据集中的标签，类型为ndarray
    :return:信息熵，类型float
    '''

    #*********** Begin ***********#
    label = np.asarray(label)
    n = label.shape[0]
    if n == 0:
        return 0.0
    _, cnt = np.unique(label, return_counts=True)
    prob = cnt.astype(float) / float(n)
    ent = -np.sum(prob * np.log2(prob))
    return float(ent)
    #*********** End *************#


# 计算条件熵
def calcHDA(feature, label, index, value):
    '''
    计算信息熵
    :param feature:数据集中的特征，类型为ndarray
    :param label:数据集中的标签，类型为ndarray
    :param index:需要使用的特征列索引，类型为int
    :param value:index所表示的特征列中需要考察的特征值，类型为int
    :return:信息熵，类型float
    '''

    #*********** Begin ***********#
    feature = np.asarray(feature)
    label = np.asarray(label)
    mask = (feature[:, index] == value)
    sub = label[mask]
    m = sub.shape[0]
    if m == 0:
        return 0.0
    _, cnt = np.unique(sub, return_counts=True)
    prob = cnt.astype(float) / float(m)
    ent = -np.sum(prob * np.log2(prob))
    return float(ent)
    #*********** End *************#


def calcInfoGain(feature, label, index):
    '''
    计算信息增益
    :param feature:测试用例中字典里的feature
    :param label:测试用例中字典里的label
    :param index:测试用例中字典里的index，即feature部分特征列的索引
    :return:信息增益，类型float
    '''

    #*********** Begin ***********#
    feature = np.asarray(feature)
    label = np.asarray(label)
    n = label.shape[0]
    if n == 0:
        return 0.0
    # 总熵 H(D)
    h_d = calcInfoEntropy(feature, label)
    # 条件熵 H(D|A) = sum_v P(A=v) * H(D|A=v)
    cond = 0.0
    col = feature[:, index]
    for v in np.unique(col):
        mask = (col == v)
        cnt = int(np.sum(mask))
        if cnt == 0:
            continue
        p_v = cnt / float(n)
        cond += p_v * calcHDA(feature, label, index, v)
    return float(h_d - cond)
    #*********** End *************#