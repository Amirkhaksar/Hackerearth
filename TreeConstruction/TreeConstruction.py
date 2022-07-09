'''
Language: Python
ID: ujjwals-problem-9227da73
QLink: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/ujjwals-problem-9227da73/
Author: AmirZoyber
'''

def dfs(root,par):
    temp=1
    for child in graph[root]:
        if child!=par:
            temp*=(dfs(child,root)+1)
    ans[0]+=temp
    return temp

n=int(input())
graph=[[] for _ in range(n)]
for _ in range(n-1):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
ans=[0]

dfs(0,-1)
print((ans[0]+1)%(10**9+7))