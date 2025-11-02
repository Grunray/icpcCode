# -*- coding: utf-8 -*-
def pearson(data_x, data_y):
    """计算某一属性列与类别的相关性
    参数:
        data_x  - pandas.dataframe格式，原始数据集中的某一列数据
        data_y  - pandas.dataframe格式，原始数据集中的类别
    返回值：
        value - pearson系数
    """
    value = 0
    #   请在此添加实现代码     #
    #********** Begin *********#
    try:
        x = data_x.iloc[:, 0]
    except Exception:
        x = data_x
    try:
        y = data_y.iloc[:, 0]
    except Exception:
        y = data_y
    x = x.astype(float)
    y = y.astype(float)
    m = x.notna() & y.notna()
    x = x[m]
    y = y[m]
    n = x.size
    if n <= 1:
        value = 0.0
    else:
        mx = x.mean()
        my = y.mean()
        dx = x - mx
        dy = y - my
        sx = ((dx**2).sum()/(n-1))**0.5
        sy = ((dy**2).sum()/(n-1))**0.5
        if sx == 0 or sy == 0:
            value = 0.0
        else:
            sxy = ((dx*dy).sum()/(n-1))
            value = sxy/(sx*sy)
    #********** End ***********#
    return ("%.4f" % value)