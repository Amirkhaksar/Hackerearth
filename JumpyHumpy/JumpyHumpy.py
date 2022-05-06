'''
Language: python
ID: jumpy-humpy-5e0231d6
QLink: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/jumpy-humpy-5e0231d6/
Author: AmirZoyber
'''
n = input()
arr = [int(x) for x in input().strip().split()]
stack =[]
best = ans = 0
for x in arr[::-1]:
    while stack and stack[-1] <= x:
        ans = ans ^ stack.pop()
    stack.append(x)
    ans = ans ^ x
    best = max(best,ans)
print(best)

