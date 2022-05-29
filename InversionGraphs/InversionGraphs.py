'''
Language: python
ID: inversion-graph-4670b723
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/inversion-graph-4670b723/
Author: AmirZoyber
'''
def Ceil(A, l, r, key): 
    while (r - l > 1):
        m = l + (r - l)//2
        if (A[m] >= key): r = m 
        else: l = m 
    return r 
    
size=int(input())
a=list(map(int,input().split()));A=a[::-1]
tailTable = [0 for i in range(size + 1)] 
len = 0 ;tailTable[0] = A[0];len = 1
for i in range(1, size): 
    if (A[i] < tailTable[0]): tailTable[0] = A[i] 
    elif (A[i] > tailTable[len-1]): 
        tailTable[len] = A[i] 
        len+= 1
    else: tailTable[Ceil(tailTable, -1, len-1, A[i])] = A[i] 
print(len)