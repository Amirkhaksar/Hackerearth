# -*- coding: utf-8 -*-
'''
language = python

id = Breaking walls

qlink = https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/break-the-wall-acf543a5/

author: amir hejazi

'''
from sys import stdin
input = stdin.readline
 
def BFS(grid, N, M, line, column, zones, index):
    stars = 0
    queue = [(line, column)]
    while queue:
        line, column = queue.pop()
        if zones[line][column] == None:
            zones[line][column] = index
            if grid[line][column] == '*':
                stars += 1
            for dline, dcolumn in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                if 0 <= line + dline < N and 0 <= column + dcolumn < M:
                    if grid[line + dline][column + dcolumn] != '#' and zones[line + dline][column + dcolumn] == None:
                        queue.append((line + dline, column + dcolumn))
    return zones, stars
 
def getzones(grid, N, M):
    zones = [[None] * M for line in range(N)]
    stars = []
    for line in range(N):
        for column in range(M):
            if grid[line][column] != '#' and zones[line][column] == None:
                zones, count = BFS(grid, N, M, line, column, zones, len(stars))
                stars.append(count)
    return zones, stars
 
def connectivity(grid, N, M, zones):
    connect = set()
    for line in range(N):
        for column in range(M):
            if grid[line][column] == '#':
                if 0 <= line - 1 < N and 0 <= line + 1 < N:
                    if grid[line - 1][column] != '#' and grid[line + 1][column] != '#':
                        zone1 = zones[line - 1][column]
                        zone2 = zones[line + 1][column]
                        if zone1 != zone2: connect.add((min(zone1, zone2), max(zone1, zone2)))
                if 0 <= column - 1 < M and 0 <= column + 1 < M:
                    if grid[line][column - 1] != '#' and grid[line][column + 1] != '#':
                        zone1 = zones[line][column - 1]
                        zone2 = zones[line][column + 1]
                        if zone1 != zone2: connect.add((min(zone1, zone2), max(zone1, zone2)))
    return connect
 
def solve(grid, N, M):
    zones, stars = getzones(grid, N, M)
    connect = connectivity(grid, N, M, zones)
    maximum = 0
    for i, j in connect:
        maximum = max(maximum, stars[i] + stars[j])
    return maximum
 

N, M = [int(x) for x in input().strip().split()]
grid = []
for line in range(N):
    grid.append(input().strip())
print(solve(grid, N, M))
