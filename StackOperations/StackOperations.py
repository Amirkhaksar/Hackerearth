'''
Language: python
ID: stakth-1-e6a76632
QLink: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/stakth-1-e6a76632/
Author: AmirZoyber
'''
n,k = map(int, input().split())
arr=list(map(int,input().split()))
if (k==n or (n==1 and k%2==1)):
    print(-1)
elif (k>n):
    print(max(arr))
else:
    temp=-1
    for i in range(0,k-1):
        temp=max(temp,arr[i])
    ans=max(temp,arr[k])
    print(ans)