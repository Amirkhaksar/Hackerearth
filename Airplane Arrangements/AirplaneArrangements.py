
#Language:C++
#ID:Airplane Arrangements
#QLink:https://www.hackerearth.com/problem/algorithm/airplane-arrangements-4d8a1bca/
#All Accepet
#Author:Amirkhaksar


import math
mod = 1000000007
n, m = map(int, input().split())

print (pow(2*(n+1), m, mod) * pow(n+1, mod-2, mod) % mod * (n+1-m) % mod)
