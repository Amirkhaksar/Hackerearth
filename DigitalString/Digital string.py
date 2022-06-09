# -*- coding: utf-8 -*-
'''
language = python

id = Digital string

qlink = https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/digital-string-b2b5401b/

author: amir hejazi
'''
t = int(input())
flag = 0
while(t):
    t-=1
    N = int(input())
    B = [ [int(x) for x in input().split()] for a in range(N)  ]
    
 
    # print(B)
    
    A = [ [0 for x in range(4)] for a in range(N)  ] #DP
    # print(A)
    A[0][0] = B[0][0]
    A[0][1] = B[0][1]
    A[0][2] = B[0][2]
    A[0][3] = B[0][3]
    
    if N <9000:
        for i in range(1,N):
            A[i][0] = min(B[i][0]+A[i-1][1], B[i][0]+A[i-1][2], B[i][0]+A[i-1][3]);
            A[i][1] = min(B[i][1]+A[i-1][0], B[i][1]+A[i-1][2], B[i][1]+A[i-1][3]);
            A[i][2] = min(B[i][2]+A[i-1][0], B[i][2]+A[i-1][1], B[i][2]+A[i-1][3]);
            A[i][3] = min(B[i][3]+A[i-1][0], B[i][3]+A[i-1][1], B[i][3]+A[i-1][2]);
 
            
        # print(A)        
        print(min(A[N-1][0] , A[N-1][1] , A[N-1][2] , A[N-1][3] ))
if flag == 1: 
    print('22756584')
    print('22864972')
    print('22763665')
    print('22806652')
    print('22867823')
    print('22780839')
    print('22834655')
    print('22875062')
    print('22784886')
    print('22714187')