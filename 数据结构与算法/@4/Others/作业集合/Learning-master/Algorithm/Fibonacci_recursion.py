# -*- coding: utf-8 -*-
"""
Created on Thu Jan 21 23:24:36 2016

@author: biochen
"""

def Fibonacci_recursion(Num):
    if Num == 1 or Num == 2 :
        return 1
    else:
        return Fibonacci_recursion(Num - 1) + Fibonacci_recursion(Num - 2)

print(Fibonacci_recursion(50))

