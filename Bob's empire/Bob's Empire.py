'''
language = python

id = Bob's empire

qlink = https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/bob-empire-4955c35b/

author: amir hejazi
'''
t = int(input())

for t_ in range (t):
    n = int (input ())
    abcd1 = list(input().split())
    abcd2=map(int, abcd1)
    mn = min (abcd2)
    print (str (((mn + n - 1) // mn) + 3) + '\n')


