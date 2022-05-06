'''
Language: python
ID: median-game-june-easy-19-3722be60
QLink: https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/median-game-june-easy-19-3722be60/
Author: AmirZoyber
'''
t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    print (min(a)+max(a))
