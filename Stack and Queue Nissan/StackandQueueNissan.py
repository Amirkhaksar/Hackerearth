#Language:python
#ID:StackandQueue<Nissan>
#QLink:https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/staque-1-e790a29f/
#All Accepet
#Author:Amirkhaksar


n, k = list(map(int, input().split()))

a = list(map(int, input().split()))

sumnumber = 0

ss = 0

count = 0

for i in range(n):

    if i >= n-k:

        sumnumber += a[i]

for i in range(k):

    ss += a[i]

    sumnumber -= a[n-k+i]

    if count < ss+sumnumber:

        count = ss + sumnumber

print(count)
