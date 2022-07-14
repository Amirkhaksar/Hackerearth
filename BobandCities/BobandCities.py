'''
Language: Python
ID: bob-and-cities-dfc06921
QLink: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/bob-and-cities-dfc06921/
Author: AmirZoyber
'''
import heapq

n,m=map(int,input().split())
ar=[]
for _ in range(n):
    temp=input()
    ar.append(temp)

l,r,u,d=map(int,input().split())
x,y=map(int,input().split())
x=x-1;y=y-1

k=int(input())
lis=[];ans=[]
heapq.heapify(lis)

for i in range(k):
    num=int(input())
    ans.append([num,0])
    heapq.heappush(lis,(num,i))
class A:
    def __init__(self,startx,starty,timet):
        self.startx=startx
        self.starty=starty
        self.timet=timet
    def __lt__(self,other):
        if self.timet<other.timet:
            return True
        else:
            return False   
obj=A(x,y,0);q=[obj]
heapq.heapify(q)
s=set()   
ct=0;lcost=0;flag=0
fnum=heapq.heappop(lis)
xt=[0,0,-1,1];yt=[-1,1,0,0];ctt=[l,r,u,d]

while (len(q)>0):
    temp=heapq.heappop(q)
    while (temp.timet>fnum[0]):
        ans[fnum[1]][1]=ct
        if len(lis)==0:
            flag=1;break
        fnum=heapq.heappop(lis)
    if len(lis)==0 and flag==1:break
    if (temp.startx,temp.starty) in s:continue
    else:
        ct+=1
        s.add((temp.startx,temp.starty))
    for i in range(4):
        xnew=xt[i]+temp.startx
        ynew=yt[i]+temp.starty
        if xnew>=0 and xnew<n and ynew>=0 and ynew<m:
            if ar[xnew][ynew]=="#":
                continue    
            if (xnew,ynew) not in s:
                obj=A(xnew,ynew,temp.timet+ctt[i]);heapq.heappush(q,obj)    
for i in range(k):
    print(ct) if (ans[i][1]==0) else print(ans[i][1]) 