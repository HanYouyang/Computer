# -*- coding: utf-8 -*-
"""
Created on Wed Jan 20 12:07:43 2016

@author: biochen
"""

def showMaxFactor(Num):
    count = Num // 2
    while count > 1:
        if Num % count == 0:
            print("%d最大的约数是%d" % (Num, count))
            break
        count -= 1
    else:
        print("%d是素数！" % Num)

Num = int(input("请输入一个自然数"))
showMaxFactor(Num)