"""
#Language:Python
#ID:Maximum Sum of Building Speed
#QLink:https:https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/maximum-sum-of-building-speed-00ab8996/
#All Accepet
#Author:Amirkhaksar
"""
n=int(input())

a=list(map(int,input().split()))

a.sort()

t=0

for i in range(2*n-2,-1,-2):

     t+=a[i]

print(t)