'''
Language: Python
ID: /permutation-swaps
QLink: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/permutation-swaps/
Author: AmirZoyber
'''
from collections import defaultdict,deque
def bfs(v,src,count):
    q=deque();q.append(src)
    k={};k[src]=1
    visited[src]=count
    while (q):
        s=q.popleft()
        for j in v[s]:
            if (j not in k):
                q.append(j);k[j]=1
                visited[j]=count
for _ in range(int(input())):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    d=defaultdict(list)
    ans=True
    for __ in range(m):
        x,y=map(int,input().split())
        d[a[x-1]].append(a[y-1]);d[a[y-1]].append(a[x-1])
    visited={}
    for i in range(1,n+1):
        if (i not in visited):bfs(d,i,i)
    for i in range(n):
        if (a[i]!=b[i]):
            if (visited[a[i]]!=visited[b[i]]):ans=False;break
    print("YES") if (ans) else print("NO")