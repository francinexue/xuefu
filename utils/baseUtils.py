# -*- coding: utf-8 -*-
"""
Created on Sat Aug 01 17:28:29 2017
存储一些基础的小函数
@author: lenovo
"""
import os
def getAbsolutePath(relativePath):
    '''
    将相对路径转化为绝对路径，因为使用在一个工程中引用另一个文件的相对路径时，会加载该运行文件的目录，导致相对引用出错
    :param relativePath:
    :return:
    '''
    pathList = relativePath.split('/')
    pathList = [i for i in pathList if i != '..']
    path = os.path.join(os.path.dirname(os.path.abspath(__file__)).split('tquant')[0], 'tquant','quant',*pathList)
    return path

if __name__ =='__main__':
    print getAbsolutePath('../../api/stock/a.csv')