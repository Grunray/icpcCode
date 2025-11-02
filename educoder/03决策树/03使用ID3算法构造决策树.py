import numpy as np
from copy import deepcopy

class DecisionTree(object):
    #计算熵
    def calcInfoEntropy(self, label):
        label_set = set(label)
        result = 0
        for l in label_set:
            count = 0
            for j in range(len(label)):
                if label[j] == l:
                    count += 1
            p = count/len(label)
            result -= p*np.log2(p)
        return result

    #计算条件熵
    def calcHDA(self, feature, label, index, value):
        count = 0
        sub_feature = []
        sub_label = []
        for i in range(len(feature)):
            if feature[i][index] == value:
                count += 1
                sub_feature.append(feature[i])
                sub_label.append(label[i])
        pHA = count/len(feature)
        e = self.calcInfoEntropy(sub_label)
        return pHA*e


    #计算信息增益
    def calcInfoGain(self, feature, label, index):
        base_e = self.calcInfoEntropy(label)
        f = np.array(feature)
        f_set = set(f[:, index])
        sum_HDA = 0
        for l in f_set:
            sum_HDA += self.calcHDA(feature, label, index, l)
        return base_e - sum_HDA


    def __init__(self):
        #决策树模型
        self.tree = {}

    def fit(self, feature, label):
        '''
        :param feature: 训练数据集所有特征组成的ndarray
        :param label:训练数据集中所有标签组成的ndarray
        :return: None
        '''

        #************* Begin ************#
        feature = np.asarray(feature)
        label = np.asarray(label)
        vals, cnts = np.unique(label, return_counts=True)
        self.default_label = vals[int(np.argmax(cnts))]
        def majority(l):
            v, c = np.unique(l, return_counts=True)
            return v[int(np.argmax(c))]
        def build(f, y, idxs):
            if y.size == 0:
                return self.default_label
            if np.unique(y).size == 1:
                return y[0]
            if len(idxs) == 0:
                return majority(y)
            sub = f[:, idxs]
            if np.unique(sub, axis=0).shape[0] == 1:
                return majority(y)
            gains = []
            for j in idxs:
                gains.append((self.calcInfoGain(f, y, j), j))
            best = max(gains, key=lambda t: t[0])[1]
            branch = {}
            for v in np.unique(f[:, best]):
                m = (f[:, best] == v)
                child = build(f[m], y[m], [x for x in idxs if x != best])
                branch[v] = child
            return {best: branch}
        self.tree = build(feature, label, list(range(feature.shape[1])))
        #************* End **************#

    def predict(self, feature):
        '''
        :param feature:训练数据集所有特征组成的ndarray
        :return:预测结果，如np.array([0, 1, 2, 2, 1, 0])
        '''

        #************* Begin ************#
        f = np.asarray(feature)
        res = []
        for i in range(f.shape[0]):
            node = deepcopy(self.tree)
            while isinstance(node, dict):
                k = next(iter(node.keys()))
                branch = node[k]
                v = f[i][k]
                if v in branch:
                    node = branch[v]
                else:
                    node = getattr(self, 'default_label', 0)
                    break
            res.append(node)
        return np.asarray(res)
        #************* End **************#