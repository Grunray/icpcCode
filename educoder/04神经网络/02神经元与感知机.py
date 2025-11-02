#encoding=utf8

import numpy as np
#构建感知机算法
class Perceptron(object):
    def __init__(self, learning_rate = 0.01, max_iter = 200):
        self.lr = learning_rate
        self.max_iter = max_iter
    def fit(self, data, label):
        '''
        input:data(ndarray):训练数据特征
              label(ndarray):训练数据标签
        output:w(ndarray):训练好的权重
               b(ndarry):训练好的偏置
        '''
        #编写感知机训练方法，w为权重，b为偏置
        self.w = np.random.randn(data.shape[1])
        self.b = float(np.random.rand(1))
        #********* Begin *********#
        x = np.asarray(data, dtype=float)
        y = np.asarray(label, dtype=int)
        u = np.unique(y)
        if set(u.tolist()) == {0,1}:
            y = 2*y - 1
        for t in range(self.max_iter):
            e = 0
            for i in range(x.shape[0]):
                s = y[i] * (np.dot(self.w, x[i]) + self.b)
                if s <= 0:
                    self.w += self.lr * y[i] * x[i]
                    self.b += self.lr * y[i]
                    e += 1
            if e == 0:
                break
        #********* End *********#
        return None
    def predict(self, data):
        '''
        input:data(ndarray):测试数据特征
        '''
        #编写感知机预测方法，若是正类返回1，负类返回-1
        #********* Begin *********#        
        x = np.asarray(data, dtype=float)
        if x.ndim == 1:
            s = np.dot(self.w, x) + self.b
            return 1 if s >= 0 else -1
        s = x.dot(self.w) + self.b
        return np.where(s >= 0, 1, -1)
        #********* End *********#