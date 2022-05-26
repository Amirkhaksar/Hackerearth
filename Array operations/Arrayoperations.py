#Language:Python
#ID:Array operations
#QLink:https://www.hackerearth.com/problem/algorithm/array-operations-3-96b9f0e0/
#All Accepet
#Author:Amirkhaksar

t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))
    s = 0
    pre = [0]
    for x in a:
        s = max(s + x, 0)
        pre += [s]
    ans = mx = s = 0
    for i in range(n - 1, -1, -1):
        s = max(s + a[i], 0)
        mx = max(s, mx)
        ans = max(ans, mx + pre[i])
    print(ans)