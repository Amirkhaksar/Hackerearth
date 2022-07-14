# -*- coding: utf-8 -*-
'''
language = python

id = Minimum cost

qlink = https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/pasha-jumps-on-a-permutation-june-easy-19-9e608b68/

author: amir hejazi
'''
import sys
sys.setrecursionlimit(100000)
 
t = int(input())
for _ in range(t):
    n = int(input())
    arr = [0]+[int(i) for i in input().split()]
    q = [1]
    visited = set()
 
    def dfs(ele,qu):
        while arr[qu[-1]] not in visited:
            ele = qu[-1]
            qu.append(arr[ele])
            visited.add(arr[ele])
        return qu 
 
    val = 0
    flag = 0
    while q:
        sec_q = []
        new_q = []
        for node in q:
            if node not in visited:
                sec_q.append(node)
                visited.add(node)
                sec_q = dfs(node,sec_q)
        #print(sec_q)
        for ele in sec_q:
            if ele==n:
                print(val)
                flag = 1
                break
            if ele+1 not in visited and ele+1<=n:
                new_q.append(ele+1)
            if ele-1 not in visited and ele-1>=1:
                new_q.append(ele-1)
        if flag==1:
            break
        val+=1
        q = new_q 
    if flag==0:
        print('Not found')