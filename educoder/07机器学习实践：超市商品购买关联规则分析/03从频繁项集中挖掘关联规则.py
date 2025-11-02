from utils import apriori, aprioriGen

def calcConf(freqSet, H, supportData, brl, minConf = 0.7):
    prunedH = []
    for conseq in H:
        conf = supportData[freqSet]/supportData[freqSet - conseq]
    if conf >= minConf:
        brl.append((freqSet - conseq, conseq, conf))
        prunedH.append(conseq)
    return prunedH

def ruleFromConseq(freqSet, H, supportData, brl, minConf = 0.7):
    m = len(H[0])
    if len(freqSet) > m+1:
        Hmp1 = aprioriGen(H, m+1)
        Hmp1 = calcConf(freqSet, Hmp1, supporData, brl, minConf)
        if len(Hmp1) > 1:
            ruleFromConseq(freqSet, Hmp1, supportData, brl, minConf)


def generateRules(dataset, minsupport, minConf):
    '''
    生成关联规则，可以使用apriori函数获得数据集中的频繁项集列表与支持度
    :param dataset:数据集，类型为list
    :param minsupport:最小支持度，类型为float
    :param minConf:最小可信度，类型为float
    :return:关联规则列表，类型为list
    '''
    #*********Begin*********#
    L,s=apriori(dataset,minsupport)
    br=[]
    def fconf(fs,H):
        p=[]
        for c in H:
            lhs=fs-c
            if len(lhs)==1 and next(iter(lhs))!=min(fs):
                continue
            conf=s[fs]/s[lhs]
            if conf>=minConf:
                br.append((lhs,c,conf))
                p.append(c)
        return p
    def rf(fs,H):
        if not H:
            return
        m=len(H[0])
        if len(fs)>m+1:
            Hmp1=aprioriGen(H,m+1)
            Hmp1=fconf(fs,Hmp1)
            if len(Hmp1)>1:
                rf(fs,Hmp1)
    for i in range(1,len(L)):
        for fs in L[i]:
            H1=[frozenset([x]) for x in fs]
            if i>1:
                rf(fs,H1)
            else:
                fconf(fs,H1)
    return br
    #*********End*********#

