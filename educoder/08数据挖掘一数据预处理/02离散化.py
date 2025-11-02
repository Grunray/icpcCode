# -*- coding: utf-8 -*-
def discretization(data):
    """对连续型数据离散化
     0-17 -> 0
    18-44 -> 1
    45-59 -> 2
    60-   -> 3
    参数:
        data - pandas.dataframe格式，原始数据中的一列

    返回值：
        processed_data - 离散化后的数据
    """
    processed_data = data
    #   请在此添加实现代码     #
    #********** Begin *********#
    try:
        s = data.iloc[:, 0]
    except Exception:
        s = data
    r = s.copy()
    r[(s >= 0) & (s <= 17)] = 0
    r[(s >= 18) & (s <= 44)] = 1
    r[(s >= 45) & (s <= 59)] = 2
    r[s >= 60] = 3
    processed_data = r
    #********** End ***********#
    return processed_data