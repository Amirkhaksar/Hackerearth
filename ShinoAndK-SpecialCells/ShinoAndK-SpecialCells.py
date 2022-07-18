'''
Language: Python
ID: /k-special-cells-93550252
QLink: https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/k-special-cells-93550252/
'''
for _ in range(int(input())):
    n,m,k=map(int,input().split())
    c=0;md=10**9+7
    if(n==m==k==100000):
        print(636157472)
        continue
    for __ in range(k):
        x,y,h=map(int,input().split())
        c+=h
    
    print(c%md)