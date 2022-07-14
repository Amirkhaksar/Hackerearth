# -*- coding: utf-8 -*-
'''
language = python

id = Meet people

qlink = https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/emergency-meeting-da1fc0b5/

author: amir hejazi
'''
import sys
#from itertools import permutations, combinations;import heapq,random;
from collections import defaultdict,deque
import bisect as bi
def yes():print('YES')
def no():print('NO')
#sys.stdin=open('input.txt','r');sys.stdout=open('output.txt','w');
def I():return (int(sys.stdin.readline()))
def In():return(map(int,sys.stdin.readline().split()))
def Sn():return sys.stdin.readline().strip()
#sys.setrecursionlimit(1500)
def dict(a):
    d={} 
    for x in a:
        if d.get(x,-1)!=-1:
            d[x]+=1
        else:
            d[x]=1
    return d
def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bi.bisect_left(a, x)
    if i != len(a):
        return i
    else:            
        return -1
def df1(gp,n,st):
    q=deque([st])
    high=[-1]*(n+1)
    high[st]=0
    while q:
        node=q.popleft()
        for x in gp[node]:
            if high[x]==-1:
                high[x]=high[node]+1
                q.appendleft(x)
    return high
def main():
    try:
        n,k=In()
        gp=defaultdict(list)
        for i in range(n-1):
            a,b=In()
            gp[a].append(b)
            gp[b].append(a)
        people=[0]+list(In())
        high=df1(gp,n,1)
        st=1
        mx=0
        for i in range(1,k+1):
            if high[people[i]]>mx:
                mx=high[people[i]]
                st=people[i]
 
        high1=df1(gp,n,st)
        end=st
        mx=0
        ok=True
        for i in range(1,k+1):
            if high1[people[i]]>mx:
                mx=high1[people[i]]
                end=people[i]
            if high1[people[i]]&1==1:
                ok=False
        if not ok:
            print(-1)
            return
        dist=high1[end]-high1[st]
        if dist%2==0:
            print(dist//2)
        else:
            print(-1)
    except:
        pass
        
M = 998244353
P = 1000000007
 
if __name__ == '__main__':
    for _ in range(I()):main()