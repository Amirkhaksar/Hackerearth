# -*- coding: utf-8 -*-
'''
language = python

id = Number of ways

qlink = https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/rook-path-142e55ee/

author: amir hejazi
'''

 
def no_of_ways(mat, n, m):
    s = 0
    row = [0 for _ in range(n)]
    col = [1]
    tot = 1
    for j in range(1, m):
        if mat[0][j] == "*": tot = 0
        col.append(tot)
        tot += tot
    row[0] = 1
    for i in range(1, n):
        for j in range(m):
            if mat[i][j] == "*":
                row[i] = 0
                col[j] = 0
            else:
                s = (row[i]+col[j])%1000000007
                row[i] += s
                col[j] += s
    return s
    
 
for _ in range(int(input())):
    tmp = input().split(" ")
    n = int(tmp[0])
    m = int(tmp[1])
    mat = [input() for i in range(n)]
    print(no_of_ways(mat, n, m))