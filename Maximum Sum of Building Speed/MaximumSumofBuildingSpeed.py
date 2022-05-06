n=int(input())

a=list(map(int,input().split()))

a.sort()

t=0

for i in range(2*n-2,-1,-2):

    t+=a[i]

print(t)