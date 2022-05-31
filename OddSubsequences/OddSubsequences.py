'''
Language: python
ID: explosions-810e1162
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/explosions-810e1162/
Author: AmirZoyber
'''
mod = 1000000007
fact = [1]
for i in range(1, 1001):
    fact.append((fact[-1] * i) % mod)
for _ in range(int(input())):
    n, k = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    ans = even = odd = 0
    for i in a:
        if (i % 2):odd += 1
        else:even += 1
    for i in range(odd + 1):
        if (i % 2):
            j = k - i
            if (0 <= j <= even):
                ans += fact[odd] * pow(fact[i] * fact[odd - i] % mod, mod - 2, mod) * fact[even] * pow(
                    fact[j] * fact[even - j] % mod, mod - 2, mod)
                ans %= mod
    print(ans)