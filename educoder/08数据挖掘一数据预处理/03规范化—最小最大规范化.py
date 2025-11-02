# -*- coding: utf-8 -*-
def minmax_normalization(data):
    """对给定的某一列数据进行0—1规范化
    参数:
        data - pandas.dataframe格式，原始数据集中的某一列数据
    返回值：
        normalized_data - 0-1规则化后的数据
    """
    normalized_data = data
    #   请在此添加实现代码     #
    #********** Begin *********#
    try:
        s = data.iloc[:, 0]
    except Exception:
        s = data
    mn = s.min()
    mx = s.max()
    if mx == mn:
        r = s*0
    else:
        r = (s - mn) / (mx - mn)
    normalized_data = r
    #********** End ***********#
    return normalized_data