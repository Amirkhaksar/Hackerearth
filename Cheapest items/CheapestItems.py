"""
#Language:Python
#ID:Cheapest items
#QLink:https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/cheapest-items-d369a15d/
#All Accepet
#Author:Amirkhaksar
"""
from math import inf

t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    dp = [0] + [int(1e18)] * n
    for i in range(n):
        v, p = map(int, input().split())
        v += 1
        if v >= n:
            dp[n] = min(dp[n], dp[0] + p)
        for w in range(n, v - 1, -1):
            dp[w] = min(dp[w], dp[w - v] + p)
        for w in range(n - 1, -1, -1):
            dp[w] = min(dp[w], dp[w + 1])
    print(dp[n])