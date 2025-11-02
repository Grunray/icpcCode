#encoding=utf8
import numpy as np
from math import sqrt

#bp神经网络训练方法
def bp_train(feature,label,n_hidden,maxcycle,alpha,n_output):
    '''
    计算隐含层的输入
    input:feature(mat):特征
          label(mat):标签
          n_hidden(int)隐藏层的节点个数
          maxcycle(int):最大迭代次数
          alpha(float):学习率
          n_output(int):输出层的节点个数
    output:w0(mat):输入层到隐藏层之间的权重
           b0(mat):输入层到隐藏层之间的偏置
           w1(mat):隐藏层到输出层之间的权重
           b1(mat):隐藏层到输出层之间的偏置          
    '''
    m,n = np.shape(feature)
    w0 = np.mat(np.random.rand(n,n_hidden))
    w0 = w0*(8.0*sqrt(6)/sqrt(n+n_hidden))-\
         np.mat(np.ones((n,n_hidden)))*\
         (4.0*sqrt(6)/sqrt(n+n_hidden))
    b0 = np.mat(np.random.rand(1,n_hidden))
    b0 = b0*(8.0*sqrt(6)/sqrt(n+n_hidden))-\
         np.mat(np.ones((1,n_hidden)))*\
         (4.0*sqrt(6)/sqrt(n+n_hidden))
    w1 = np.mat(np.random.rand(n_hidden,n_output))
    w1 = w1*(8.0*sqrt(6)/sqrt(n_hidden+n_output))-\
         np.mat(np.ones((n_hidden,n_output)))*\
         (4.0*sqrt(6)/sqrt(n_hidden+n_output))
    b1 = np.mat(np.random.rand(1,n_output))
    b1 = b1*(8.0*sqrt(6)/sqrt(n_hidden+n_output))-\
         np.mat(np.ones((1,n_output)))*\
         (4.0*sqrt(6)/sqrt(n_hidden+n_output))

    i = 0
    while i <= maxcycle:
        #********* Begin *********# 
        h_in = hidden_in(feature,w0,b0)
        h_out = hidden_out(h_in)
        p_in = predict_in(h_out,w1,b1)
        p_out = predict_out(p_in)
        d1 = np.multiply(p_out - label, partial_sig(p_in))
        d0 = np.multiply(d1*w1.T, partial_sig(h_in))
        w1 -= alpha * (h_out.T * d1)
        b1 -= alpha * np.sum(d1, axis=0)
        w0 -= alpha * (feature.T * d0)
        b0 -= alpha * np.sum(d0, axis=0)
        #********* End *********#
        i +=1
    return w0,w1,b0,b1

#计算隐藏层的输入函数    
def hidden_in(feature,w0,b0):
    m = np.shape(feature)[0]
    hidden_in = feature*w0
    for i in range(m):
        hidden_in[i,] += b0
    return hidden_in

#计算隐藏层的输出函数
def hidden_out(hidden_in):
    hidden_output = sig(hidden_in)
    return hidden_output
    
#计算输出层的输入函数
def predict_in(hidden_out,w1,b1):
    m = np.shape(hidden_out)[0]
    predict_in = hidden_out*w1
    for i in range(m):
        predict_in[i,] +=b1
    return predict_in

#计算输出层的输出的函数
def predict_out(predict_in):
    result = sig(predict_in)
    return result

#sigmoid函数
def sig(x):
    return 1.0/(1+np.exp(-x))

#计算sigmoid函数偏导
def partial_sig(x):
    m,n = np.shape(x)
    out = np.mat(np.zeros((m,n)))
    for i in range(m):
        for j in range(n):
            out[i,j] = sig(x[i,j])*(1-sig(x[i,j]))
    return out
        
        
        
        
        