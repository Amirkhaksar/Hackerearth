# -*- coding: utf-8 -*-
'''
language = python

id = Strange City

qlink =https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/strange-city-ea5f4994/

author: amir hejazi
'''
from sys import stdin, stdout
 
 
class seg_tree:
    def __init__(self, a):
        n = len(a)
        self.n = n
        self.value = [None] * 2 * n
        for i in range(n):
            self.value[i + n] = [a[i]]
        for i in range(2 * n - 1, 1, -2):
            self.value[i >> 1] = self.merge_sort(self.value[i], self.value[i ^ 1])
 
 
    def merge_sort(self, a, b):
        res = []
        i = 0
        j = 0
        while True:
            if i >= len(a):
                for k in range(j, len(b)):
                    res.append(b[k])
                break
            if j >= len(b):
                for k in range(i, len(a)):
                    res.append(a[k])
                break
            if a[i] < b[j]:
                res.append(a[i])
                i += 1
            elif a[i] > b[j]:
                res.append(b[j])
                j += 1
            else:
                res.append(a[i])
                i += 1
        return res
 
 
    def binary_search_floor(self, x, a):
        l = 0
        r = len(a) - 1
        while l <= r:
            i = (l + r) // 2
            if a[i] <= x:
                l = i + 1
            else:
                r = i - 1
        return r
 
 
    def query(self, l, r, k):
        l += self.n
        r += self.n
        res = 0
        while l <= r:
            if l & 1 != 0:
                i = self.binary_search_floor(k, self.value[l])
                res += i + 1
            if r & 1 == 0:
                i = self.binary_search_floor(k, self.value[r])
                res += i + 1
            l = (l + 1) >> 1
            r = (r - 1) >> 1
        return res
 
 
def dfs(adj, costs):
    n = len(adj)
    visited = [False] * n
    visited[0] = True
    pointer = [0] * n
    start = [0] * n
    end = [0] * n
    costs_linear = [costs[0]]
    stack = [0]
    i = 0
    while stack:
        x = stack[-1]
        any_more = False
        for j in range(pointer[x], len(adj[x])):
            y = adj[x][j]
            pointer[x] += 1
            if not visited[y]:
                i += 1
                start[y] = i
                stack.append(y)
                costs_linear.append(costs[y])
                any_more = True
                visited[y] = True
                break
        if not any_more:
            stack.pop()
            end[x] = i
    return start, end, costs_linear
 
 
def solve():
    n, q, d = list(map(int, stdin.readline().strip().split()))
    d -= 1
    costs = list(map(int, stdin.readline().strip().split()))
    adj = [[] for _ in range(n)]
    for _ in range(n - 1):
        x, y = list(map(int, stdin.readline().strip().split()))
        adj[x - 1].append(y - 1)
        adj[y - 1].append(x - 1)
    start, end, costs_linear = dfs(adj, costs)
    st = seg_tree(costs_linear)
    answers = []
    ans = 0
    for _ in range(q):
        k1, k2, k3 = list(map(int, stdin.readline().strip().split()))
        r, x, y = k1 ^ ans, k2 ^ ans, k3 ^ ans
        r -= 1
        if y - costs[r] - costs[d] <= 0:
            ans = 0
        elif x - costs[r] - costs[d] <= 1:
            ans = st.query(start[r] + 1, end[r], y - costs[r] - costs[d])
        else:
            ans = st.query(start[r] + 1, end[r], y - costs[r] - costs[d]) - \
                st.query(start[r] + 1, end[r], x - costs[r] - costs[d] - 1)
        answers.append(ans)
    stdout.write('\n'.join(map(str, answers)))
 
 
solve()