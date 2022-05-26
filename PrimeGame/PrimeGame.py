"""
Language: Python
ID: prime-game-1-2604365b
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/prime-game-1-2604365b/
Author: AmirZoyber
"""
def check_prime(n):
  for i in range(2,n):
    if ((n%i) == 0):
      return False
  return True

for _ in range(int(input())):
    x = input()
    n = len(x)
    dp = [[True] * (n + 1) for __ in range(n)]
    for i in range(2, n + 1):
        j = 0;k = i
        while (k <= n):
            if (not check_prime(int(x[j:k]))) and dp[j][k - 1] and dp[j + 1][k]:
                dp[j][k] = False
            j+=1;k+=1
    print("Alice") if dp[0][n] else print("Bob")