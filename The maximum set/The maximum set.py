# -*- coding: utf-8 -*-
'''
language = python

id = The maximum set

qlink = https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/inverse-graph-4c5729e8/

author: amir hejazi

'''
from bisect import bisect_left
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().strip().split()))
    s = []
    for i in reversed(a):
        if not s or i > s[-1]:
            s.append(i)
        else:
            s[bisect_left(s, i)] = i
    print(len(s))
    
    
    
    
    
    
    
