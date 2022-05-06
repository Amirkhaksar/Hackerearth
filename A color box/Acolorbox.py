"""
#Language:Python
#ID:AColoBox
#QLink:https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/paint-box-3e9796fd/
#All Accepet
#Author:Amirkhaksar
"""

lk = list(map(int, input().split()))
n, k = lk[0], lk[1]
a = list(map(int, input().split()))
a.sort()
diff = n-k
a = a[:diff]
print(sum(a))
