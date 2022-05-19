# -*- coding: utf-8 -*-
'''
language = python

id = Bob's confusion

qlink = https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/lucky-confusion-2c714d08/

author: amir hejazi
'''
t = int(input())
 
while t>0:
    t+=-1
    flag = 'NO'
    row1 = list(map(int, input().split()))
    row2 = list(map(int, input().split()))
    row3 = list(map(int, input().split()))
    
    if row1[0] - row2[0] == row1[1] - row2[1] and row1[1] - row2[1] == row1[2]-row2[2]:
        flag = 'YES'
    elif row2[0]-row3[0] == row2[1] - row3[1] and row2[1] - row3[1] == row2[2]-row3[2]:
        flag = 'YES'
    elif row3[0]-row1[0] == row3[1] - row1[1] and row3[1] - row1[1] == row3[2]-row1[2]:
        flag = 'YES'
    
    print(flag)