# -*- coding: utf-8 -*-
def fill_median(data):
    """填充数据中的缺失值
    参数:
        data - pandas.dataframe格式，原始数据

    返回值：
        processed_data - 填充后的数据
    """
    processed_data = data
    #   请在此添加实现代码     #
    #********** Begin *********#
    processed_data = data.fillna(data.median())
    #********** End ***********#
    return processed_data