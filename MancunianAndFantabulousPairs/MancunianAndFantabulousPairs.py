'''
Language: python
ID: mancunian-and-fantabulous-pairs
QLink: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/mancunian-and-fantabulous-pairs/
Author: AmirZoyber
'''
input()
nums = list(map(int, input().split()))
pd = {}
stack = []
for i, n in enumerate(nums):
    while (stack and n > nums[stack[-1]]):
        j = stack.pop()
        gap = i-j
        sp = j-stack[-1] if stack else j+1
        pd[gap] = max(pd.get(gap, 0), sp)
    stack.append(i)
 
print(sum(pd.values()))

