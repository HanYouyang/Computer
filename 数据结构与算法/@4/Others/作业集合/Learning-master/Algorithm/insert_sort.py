# -*- coding: utf-8 -*-
"""
Created on Sat Dec  5 16:44:52 2015

@author: biochen
"""

def insert_sort(array):
    for i in range(1, len(array)):
        key = array[i]
        j = i - 1
        while j >= 0 and key < array[j]: 
            array[j + 1] = array[j]
            j = j - 1
            array[j + 1] = key

arrary = [5, 2, 4, 6, 1, 3]
insert_sort(arrary)
print(arrary)
        
