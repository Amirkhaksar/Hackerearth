"""
#Language:Python
#ID:Magic Potion
#QLink:https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/magic-potion-d54349f9/
#All Accepet
#Author:Amirkhaksar
"""

n, k = map(int, input().strip().split())
a = list(map(int, input().strip().split()))
count_arr = 0
magic_potion = n
total = 0
i = 0
j = -1
x = 0
while i < n:
    total += a[i]
    while total > k:
        j += 1
        x = 0
        total -= a[j]
    while not a[j + 1]:
        j += 1
        x += 1
    if total == k:
        count_arr += x + 1
        magic_potion = min(magic_potion, n - (i - j) - x)
    i += 1
print(count_arr, magic_potion)