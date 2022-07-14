# -*- coding: utf-8 -*-
'''
language = python

id = Gears in a machine

qlink = https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/gear-up-fa635535/

author: amir hejazi
'''
import collections
# import heapq
import io
import os
import sys
import typing
from operator import xor
from typing import List, Set, Tuple
 
# region...Input Helpers
 
out = io.BytesIO()
fd = sys.stdout.fileno()
 
 
def flush():
    os.write(1, out.getvalue())
    out.truncate(0)
    out.seek(0)
 
 
def get_string(): return sys.stdin.readline().strip()
 
 
def get_int(): return int(sys.stdin.readline().strip())
 
 
def get_ints() -> typing.Iterable[int]: return map(int, sys.stdin.readline().strip().split())
 
 
def get_ints_list(): return list(map(int, sys.stdin.readline().strip().split()))
 
 
# endregion Input Helpers
 
# region ...Modular Arithmetic
MOD = 1000000007
MODM2 = MOD - 2
 
 
def mul_mod(a, b):
    return (a * b) % MOD
 
 
def add_mod(a, b):
    r = a + b
    return r if r < MOD else r - MOD
 
 
def sub_mod(a, b):
    r = a - b
    return r if r >= 0 else r + MOD
 
 
def pow_mod(a, b):
    x = 1
    while b != 0:
        if (b & 1) == 1:
            x = mul_mod(x, a)
 
        a = mul_mod(a, a)
        b >>= 1
 
    return x
 
 
def inv_mod(a): return pow_mod(a, MODM2);
 
 
def mod(a): return a % MOD;
 
 
# endregion Modular Arithmetic
 
# region ...Helpers
 
def minmax(a: int, b: int) -> Tuple[int, int]:
    return (a, b) if a < b else (b, a)
 
 
# endregion Helpers
 
n, m, q = get_ints()
flips_direction = [i == "1" for i in sys.stdin.readline().strip().split(' ')]
flips_direction.insert(0, False)
n += 1
g: List[List[int]] = [[] for i in range(n)]
for i in range(m):
    f, t = get_ints()
    g[f].append(t)
    g[t].append(f)
 
clockwise = [False] * n
visited = [False] * n
group = [-1] * n
que = collections.deque()
 
group_id = 0
group_ok = {}
 
for i in range(1, n):
    if visited[i]:
        continue
    clockwise[i] = True
    visited[i] = True
    que.append(i)
    ok = True
    while len(que) != 0:
        f = que.popleft()
        group[f] = group_id
        d = clockwise[f]
        for t in g[f]:
            n_dir = xor(d, flips_direction[t] and flips_direction[f])
            if visited[t]:
                if n_dir != clockwise[t]:
                    ok = False
                continue
            clockwise[t] = n_dir
            visited[t] = True
            que.append(t)
    group_ok[group_id] = ok
    group_id += 1
 
for qi in range(q):
    a, b, da, db = get_ints()
    da = (da == 1)
    db = (db == 1)
    ga = group[a]
    gb = group[b]
    res = group_ok[ga] and group_ok[gb] and (ga != gb or (xor(clockwise[a], da) == xor(clockwise[b], db)))
    print("YES" if res else "NO")