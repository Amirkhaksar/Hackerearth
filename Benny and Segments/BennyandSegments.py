'''
language = python

id = benny and segments

qlink = https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/practice-problems/algorithm/benny-and-segments-marcheasy/

author: amir hejazi

'''
from sys import stdin
 
def merge(n, l):
    array = []
    read = stdin.readline
    finall = False
    for i in range(n):
        m, p = map(int, read().split())
        if finall:
            continue
 
        d = p-m
 
        if d == l:
            finall = True
 
        if d < l:
            array.append([m, p])
 
    if finall:
        return True
 
    array.sort()
 
    if not array:
        return False
 
    n = len(array)
    for i in range(n):
        q, w = array[i]
 
        target = q+l
 
        for j in range(i+1, n):
            if array[j-1][1] < array[j][0]:
                break
            if array[j][1] == target:
                return True
 
 
read = stdin.readline
t = int(read())
for t_ in range(t):
    n, l = map(int, read().split())
 
    if merge(n, l):
        print("Yes")
 
    else:
        print("No")