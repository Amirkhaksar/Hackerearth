"""
#Language:Python
#ID:Bugs
#QLink:https://www.hackerearth.com/problem/algorithm/victory-over-power-4a0cb459/
#All Accepet
#Author:Amirkhaksar
"""
import bisect,sys
li=list()
for i in range(int(sys.stdin.readline())):
    q=[int(i) for i in sys.stdin.readline().split()]
    if q[0]==1:
        if i==0:
            li.append(q[1])
        else:
            bisect.insort_left(li,q[1])
    else:
        n=len(li)
        if n<3:
            print("Not enough enemies")
        else:
            print(li[-(n//3)])