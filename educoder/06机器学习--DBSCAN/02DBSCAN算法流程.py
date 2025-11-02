#encoding=utf8
import numpy as np
import random
#寻找eps邻域内的点
def findNeighbor(j,X,eps):
    N=[]
    for p in range(X.shape[0]):
        temp=np.sqrt(np.sum(np.square(X[j]-X[p])))
        if(temp<=eps):
            N.append(p)
    return N
#dbscan算法
def dbscan(X,eps,min_Pts):
    '''
    input:X(ndarray):样本数据
          eps(float):eps邻域半径
          min_Pts(int):eps邻域内最少点个数
    output:cluster(list):聚类结果
    '''
    #********* Begin *********#
    n=X.shape[0]
    flag=np.zeros(n,dtype=int)
    cid=0
    cluster=[-1]*n
    for i in range(n):
        if flag[i]!=0:
            continue
        nbs=findNeighbor(i,X,eps)
        if len(nbs)<min_Pts:
            flag[i]=-1
            cluster[i]=-1
            continue
        cid+=1
        cluster[i]=cid
        flag[i]=cid
        q=list(nbs)
        k=0
        while k<len(q):
            j=q[k]
            if flag[j]==-1:
                cluster[j]=cid
                flag[j]=cid
            if flag[j]==0:
                flag[j]=cid
                cluster[j]=cid
                nbsj=findNeighbor(j,X,eps)
                if len(nbsj)>=min_Pts:
                    for u in nbsj:
                        if u not in q:
                            q.append(u)
            k+=1
    #********* End *********#
    return cluster