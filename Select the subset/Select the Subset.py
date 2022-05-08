'''
language = python

id = Select the subset

qlink = https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/choose-subset-d983994d/

author: amir hejazi

'''
from sys import stdin
from bisect import bisect_left
 
def soloution (v, n):
    if n == 0: 
        return 0
    tail = [0] * n
    length = 1  # always points empty slot in tail
    tail [0] = v [0]
    for i in range (1, n):
        if v [i] > tail [length - 1]:
            tail [length] = v [i]
            length += 1
        else: 
            tail [bisect_left (tail, v [i], 0, length - 1)] = v [i]
    return length
 

read = stdin.readline
t = int (read ())

for t_ in range (t):
    n = int (read ())
    
    A = list (map (int, read ().split ()))
    B = list (map (int, read ().split ()))
    
    sub = [0] * (n + 1)
    sb = [p [1] for p in sorted (zip (A, B))]
    print (soloution(sb, n))
