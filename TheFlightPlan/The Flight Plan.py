# -*- coding: utf-8 -*-
'''
language = python

id = The Flight Plan

qlink = https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/

author: amir hejazi
'''

from collections import defaultdict
 
 
def bfs():
    v[x] = 1
    q = [[x]]
    while q:
        path = q.pop(0)
        if path[-1] == y:
            print(len(path))
            print(*path)
            return
        for i in g[path[-1]]:
            if v[i] == 0:
                q.append(path + [i])
                v[i] = 1
 
 
n, m, t, c = map(int, input().split())
g = defaultdict(list)
v = defaultdict(int)
for i in range(m):
    u, ve = map(int, input().split())
    g[u].append(ve)
    g[ve].append(u)
for i in g:
    # print(i,g[i])
    g[i] = sorted(g[i])
x, y = map(int, input().split())
bfs()
