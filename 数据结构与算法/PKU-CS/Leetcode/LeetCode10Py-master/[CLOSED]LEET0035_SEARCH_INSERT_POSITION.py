#coding=utf-8

"""
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
"""
def searchinsertposition(sortedlist,target):
    if target not in sortedlist:
        sortedlist.append(target)
        sortedlist.sort()
    return sortedlist.index(target)



