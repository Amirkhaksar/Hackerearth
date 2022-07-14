# -*- coding: utf-8 -*-
'''
language = python

id = F - Lukas and Stickman

qlink = https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/f-lukas-and-stickman/

author: amir hejazi
'''
from sys import stdin
#from fractions import Fraction
from collections import Counter
#from math import comb
 
def invmod (a, m = 1000000007):
    return pow (a, m - 2, m)
 
#def res (p, q, m = 1000000007):
    #d = Fraction (p, q)
    #return d.numerator * (invmod (d.denominator)) % m
 
def main ():
    read = stdin.readline
    mod = 1000000007
    n = int (read ())
    a = list (map (int, read ().split ()))
    s = set (a)
    count = Counter (a)
    res = 0
    for a in s:
        for b in s:
            if a != b: mul = count[a] * count[b] % mod
            else: mul = count[a] * (count[b] - 1) % mod
            mul = mul * (a + b - 2) % mod
            tmp1 = (a - 1) * (a - 2) // 2 % mod
            tmp2 = (b - 1) * (b - 2) // 2 * (b - 3)    // 3 % mod
            res += mul * tmp1 % mod * tmp2 % mod
            res %= mod
    res = res * invmod (n - 2) % mod
    print (res)