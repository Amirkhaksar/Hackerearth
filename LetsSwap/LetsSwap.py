'''
Language: python
ID: lets-swap-5075ade8
QLink: https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/lets-swap-5075ade8/
Author: AmirZoyber
'''
def L_merge (n, a, b):
    mn=mnb = float ("inf")
    nh = n // 2 + 1   #midL
    li, lia = 1, 0
    for i, ia in enumerate (range (nh), 1):
        if a [ia] < mn:
            mn = a [ia]
            if b [ia] < mnb:
                mnb = b [ia]
                li, lia = i, ia
    return li, a [lia]

def R_merge (n, a, b):
    mxb=mx = 0
    nh = n // 2         #midR
    li, lia = n, n - 1
    for i, ia in zip (range (n, nh, -1), range (n - 1, nh - 1, -1)):
        if a [ia] > mx:
            mx = a [ia]
            nmxb = i - b [ia] + a [ia]
            if nmxb > mxb: mxb = nmxb
            else: return li, a [lia]
            li, lia = i, ia
    return li, a [lia]
 

n = int (input())
a = list (map(int,input().split()))
b = list (map(lambda x:abs(x[0]-x[1]),zip(a,range(1,n+1))))
sm = sum(b)
mnif,mnf = L_merge (n, a, b)
mnib,mnb = R_merge (n, a, b)
print(sm+abs(mnb-mnif)-abs(mnf-mnif)+abs(mnf-mnib)-abs(mnb-mnib))