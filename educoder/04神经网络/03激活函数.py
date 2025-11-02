#encoding=utf8


def relu(x):
    '''
    input:x(ndarray)输入数据
    '''
    #********* Begin *********#
    import numpy as np
    return np.maximum(x, 0)
    #********* End *********#