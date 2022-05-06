"""
#Language:Python
#ID:Specialty of a sequence
#QLink:hhttps://www.hackerearth.com/practice/algorithms/sorting/quick-sort/practice-problems/algorithm/lex-finds-beauty-0d0bc1b6/
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
