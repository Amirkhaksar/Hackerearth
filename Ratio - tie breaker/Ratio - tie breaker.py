# -*- coding: utf-8 -*-
'''
language = python

id = Ratio - TIE BREAKER

qlink = https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/approximate/ratio-317c498f/submissions/

author: amir hejazi
'''
def solve (arrA, arrB, K, N):
    r_min, r_max = -1000, (N+1)*1000
    r_min = -min(arrB) + 10e-6
    r = (r_min + r_max) / 2
    ratios = [a/(b+r) for a,b in zip(arrA,arrB)]
    K_pred = sum(ratios)
    while abs(K - K_pred) > 10e-6:
        if K_pred > K:
            r_min = r
            
        else:
            r_max = r
            
        r = (r_min + r_max) / 2
        ratios = [a/(b+r) for a,b in zip(arrA,arrB)]
        K_pred = sum(ratios)
    return r
        
 
data = input().split(' ')
N, col = int(data[0]), int((data[1])) 
arrA = []
arrB = []
for _ in range(N):
    data = input().split(' ')
    arrA.append(float(data[0]))
    arrB.append(float(data[1]))
    
K = float(input())
 
out_ = solve(arrA, arrB, K, N)
print (out_)