'''
Language: Python
ID: robo-path-78511fb1
QLink: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/robo-path-78511fb1/
Author: AmirZoyber
'''
def check(a,b,n,m,vis):
    if a>=0 and b>=0 and a<n and b<m and vis[a][b]==0: 
        return True
    return False

n,m=map(int,input().split())
l=[]
for _ in range(n):
    s=input()
    l.append(s)
for _ in range(int(input())):
    s1,s2,e1,e2=map(int,input().split())
    vis=[]
    for x123 in range(n):vis.append([0]*m)
    
    q=[(s1-1,s2-1,"")]
    vis[s1-1][s2-1]=1;x12=0
    
    while(len(q)):
        x=q[0];q=q[1:]
        
        if(x[0]==e1-1 and x[1]==e2-1):
            print(x[2])
            x12=1
            break
        if( check( x[0]+1, x[1], n, m, vis ) and l[ x[0]+1 ][ x[1] ]=='.'):
            q.append((x[0]+1,x[1],x[2]+"D"))
            vis[x[0]+1][x[1]]=1   
        if(check(x[0],x[1]-1,n,m,vis) and l[x[0]][x[1]-1]=='.'):
            q.append((x[0],x[1]-1,x[2]+"L"))
            vis[x[0]][x[1]-1]=1          
        if(check(x[0],x[1]+1,n,m,vis) and l[x[0]][x[1]+1]=='.'):
            q.append((x[0],x[1]+1,x[2]+"R"))
            vis[x[0]][x[1]+1]=1         
        if(check(x[0]-1,x[1],n,m,vis) and l[x[0]-1][x[1]]=='.'):
            q.append((x[0]-1,x[1],x[2]+"U"))
            vis[x[0]-1][x[1]]=1
            
    if (x12==0):print("Impossible")