# -*- coding: utf-8 -*-
'''
language = python

id = Holi and Division Function

qlink = https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/holi-and-division-function-1dfc3294/

author: amir hejazi
'''

from sys import stdin
from collections import Counter
 
def hru (n): # half round up
    return int (n + .5)
 
def main ():
    read = stdin.readline
    t = int (read ())
    for t_ in range (t):
        n = int (read ())
        a = list (map (int, read ().split ()))
        cnt = Counter (a)
        frq = [0, cnt [1]]
        for i in range (2, 100001):
            frq.append (frq [-1] + cnt [i])
        ans = 0
        for i in range (1, 100001):
            if (frq [i] - frq [i - 1]):
                bottom = int (i / 2 - (i % 2 == 0))
                top = bottom + i
                for j in range (1, 100001):
                    if bottom > 100000: break
                    ans += j * (frq [i] - frq [i - 1]) * (frq [top if top < 100001 else 100000] - frq [bottom])
                    top += i
                    bottom += i
        print (ans)
 
if __name__ == "__main__": main ()