# -*- coding: utf-8 -*-
'''
language = python

id = Number Sum

qlink = https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/abcd-26-81bc0a09/

author: amir hejazi

'''
n = int(input())

lst = list(map(int, input().strip().split()))

if lst == sorted(lst):
    print(n*(n+1))
else:
    print(n*(n+1)//2)