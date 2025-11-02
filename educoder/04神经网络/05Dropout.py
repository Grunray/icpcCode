#encoding=utf8
import numpy as np

#由于Dropout方法输出存在随机性，我们已经设置好随机种子，你只需要完成Dropout方法就行。
class Dropout:
    def __init__(self,dropout_ratio=0.5):
        self.dropout_ratio = dropout_ratio
        self.mask = None
    
    def forward(self,x,train_flg=True):
        '''
        前向传播中self.mask会随机生成和x形状相同的数组，
        并将值比dropout_ratio大的元素设为True，
        x为一个列表。  
        '''
        #********* Begin *********#
        x = np.asarray(x)
        if train_flg:
            self.mask = np.random.rand(*x.shape) > self.dropout_ratio
            return x * self.mask
        return x * (1.0 - self.dropout_ratio)
        #********* End *********#

    def backward(self,dout):
        '''
        前向传播时传递了信号的神经元，
        反向传播时按原样传递信号。
        前向传播没有传递信号的神经元，
        反向传播时信号就停在那里。
        dout为一个列表。 
        '''
        #********* Begin *********#
        dout = np.asarray(dout)
        return dout * self.mask
        #********* End *********#
