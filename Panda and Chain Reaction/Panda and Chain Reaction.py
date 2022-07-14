# -*- coding: utf-8 -*-
'''
language = python

id = Panda and Chain Reaction

qlink = https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/panda-and-chain-reaction/submissions/

author: amir hejazi
'''
from sys import stdin
 
def ff (fac, n, mod):
    ln = len (fac)
    if n < ln: return fac [n]
    for i in range (ln, n + 1):
        fac.append (fac [i - 1] * i % mod)
    return fac [-1]
 
def main ():
    read = stdin.readline
    t = int (read ())
    mod = 1000003
    fac = [1, 1]
    for t_ in range (t):
        n, x = map (int, read ().split ())
        if x >= mod: print (0)
        else: print (ff (fac, n, mod) * x % mod)