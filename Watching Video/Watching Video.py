# -*- coding: utf-8 -*-
'''
language = python

id = Watching Video

qlink = https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/video-watching-8c6cbee6/

author: amir hejazi

'''
n, d = map(int, input().split())
lst = list(map(int, input().split()))
i = len(lst) - 1
t = 1
while(lst[i] == 0):
    i -= 1
lst = lst[:i+1]
cach = 0
for i in lst:
    cach += i
    if cach >= d:
        cach -= d
    else:
        t += 1
print(t)