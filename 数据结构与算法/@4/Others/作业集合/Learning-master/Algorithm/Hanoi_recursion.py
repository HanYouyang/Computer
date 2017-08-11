# -*- coding: utf-8 -*-
"""
Created on Thu Jan 21 23:38:21 2016

@author: biochen
"""
def Hanoi_recursion(n, x, y, z):
    if n ==1:
        print (x, "-->", z)
    else:
        Hanoi_recursion(n-1, x, z, y) #将前n-1个盘子从x移动到y上
        print (x, "-->", z)#将最底下最后一个盘子从x移动到z上
        Hanoi_recursion(n-1, y, x, z)#将y上n-1个盘子移动到z上

Hanoi_recursion(8, "x", "y", "z")
