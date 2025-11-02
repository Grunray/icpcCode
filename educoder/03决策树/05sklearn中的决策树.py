from sklearn.tree import DecisionTreeClassifier

def iris_predict(train_sample, train_label, test_sample):
    '''
    实现功能：1.训练模型 2.预测
    :param train_sample: 包含多条训练样本的样本集，类型为ndarray
    :param train_label: 包含多条训练样本标签的标签集，类型为ndarray
    :param test_sample: 包含多条测试样本的测试集，类型为ndarry
    :return: test_sample对应的预测标签
    '''
    
    # ************* Begin ************#
    clf = DecisionTreeClassifier(criterion='gini', splitter='best', max_depth=3, random_state=0)
    clf.fit(train_sample, train_label)
    return clf.predict(test_sample)
    # ************* End **************#