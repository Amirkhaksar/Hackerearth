'''
Language: Python3.9
ID: maximum-beauty-subsequence-764b18e3
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/maximum-beauty-subsequence-764b18e3/
Author: AmirZoyber
'''
n=int(input())
s=input()
m=int(input())
d={};alf='abcdefghijklmnopqrstuvwxyz'
az={i:[0,0] for i in alf}
g=[[0 for i in range(26)] for j in range(26)]
for i in range(m):
    a,b,c=map(str,input().split())
    i,j=ord(a)-ord('a'),ord(b)-ord('a')
    g[i][j]+=int(c)
ans=0
for i in range(n):
    mx=0
    b=ord(s[i])-ord('a')
    for a in range(26):
        ch=chr(a+ord('a'))
        mx=max(mx,az[ch][0]+az[ch][1]*g[a][b])
    az[s[i]][0]=max(az[s[i]][0],mx)
    az[s[i]][1]=1
    ans=max(ans,az[s[i]][0])
print(ans)