# -*- coding: utf-8 -*-
'''
language = python

id =A sign of place

qlink = https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/place-sign-3bb0be4c/

author: amir hejazi
'''
from sys import stdin, stdout
input = stdin.readline
 
MODULO = 10 ** 9 + 7
 
def update(dp, array):
    total = 0
    for i in array:
        tmp = dp[i]
        dp[i] = total
        total = (total + tmp) % MODULO
    return dp
 
def solve(S, N):
    dp = [None] + [1] * (N + 1)
    for char in S:
        if char == '<':
            dp = update(dp, range(1, N + 1))
        elif char == '>':
            dp = update(dp, reversed(range(1, N + 1)))
    return sum(dp[i] for i in range(1, N + 1)) % MODULO
 

N = int(input().strip())
S = input().strip()
print(solve(S, N))