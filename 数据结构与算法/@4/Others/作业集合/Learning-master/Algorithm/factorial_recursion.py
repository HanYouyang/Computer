# -*- coding: utf-8 -*-
"""
Created on Thu Jan 21 23:20:22 2016

@author: biochen
"""

def factorial_recursion(Num):
    if Num == 1:
        return 1
    else:
        return factorial_recursion(Num - 1) * Num

print(factorial_recursion(5))