'''
Language: python
ID: gaurav-and-subarray-3-787fb90a
QLink: https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/gaurav-and-subarray-3-787fb90a/
Author: AmirZoyber
'''
def count_ones(n):
    c=0
    while (n):
        n=n&(n-1);c+=1
    return c
 
def minimum(arr,n,k):
    s=start=end=0;l=n+1
    while (end<n): 
        while ((s<k) and (end<n)): 
            s += arr[end];end+= 1  
        while ((s>=k) and (start<n)):            
            if ((end-start) < l): 
                l=end-start    
            s-=arr[start] 
            start+=1
    return l

n,q = map(int, input().split())
a=[int(x) for x in input().split()]
for i in range(len(a)):
    a[i] = count_ones(a[i])
for _ in range(q):
    k = int(input())
    if k ==0:
        print(1)
        continue
    temp = minimum(a,n,k)
    if temp<=n:
        print(temp)
    else:
        print(-1)