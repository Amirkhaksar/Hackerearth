'''
Language: Python
ID: jump-k-forward-250d464b
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/jump-k-forward-250d464b/
Author: AmirZoyber
'''
n,k = map(int,input().split())
a = [0]*n
b = [0]*(n+1)
a[n-1]=b[n-1]=1
mod = (1*9)+7
for i in range(n-2,-1,-1):
    a[i] = (b[i+1]-b[min(n,i+1+k)]) % mod
    b[i] = (a[i] + b[i+1]) % mod
print(a[0])