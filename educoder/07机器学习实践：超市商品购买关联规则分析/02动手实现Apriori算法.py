def createC1(dataset):
    C1 = set()
    for t in dataset:
        for item in t:
            item_set = frozenset([item])
            C1.add(item_set)
    return C1

def scanD(D, ck, minsupport):
    ssCnt = {}
    for tid in D:
        for can in ck:
            if can.issubset(tid):
                if can not in ssCnt.keys():
                    ssCnt[can] = 1
                else:
                    ssCnt[can] += 1
    numItems = len(D)
    reList = []
    supportData = {}
    for key in ssCnt:
        support = ssCnt[key]/numItems
        if support >= minsupport:
            reList.insert(0, key)
        supportData[key] = support
    return reList, supportData

def aprioriGen(Lk, k):
    retList = []
    lenLk = len(Lk)
    for i in range(lenLk):
        for j in range(i+1, lenLk):
            L1 = list(Lk[i])[k:-2]
            L2 = list(Lk[j])[:k-2]
            if L1 == L2:
                retList.append(Lk[i] | Lk[j])
    return retList


def apriori(dataSet, minsupport=0.5):
    '''
    apriori算法
    :param dataSet: 原始数据集
    :param minsupport: 最小支持度阈值
    :return: 候选频繁项集列表，所有候选频繁项集的支持度(包括低于阈值的)，类型为 (list, dict)
    '''
    #*********Begin*********#
    D=list(map(set,dataSet))
    C1=createC1(dataSet)
    L1,s1=scanD(D,C1,minsupport)
    L=[L1]
    sd=dict(s1)
    k=2
    while len(L[k-2])>0:
        Ck=aprioriGen(L[k-2],k)
        Lk,sk=scanD(D,Ck,minsupport)
        sd.update(sk)
        L.append(Lk)
        if not Lk:
            break
        k+=1
    return L,sd
    #*********End*********#