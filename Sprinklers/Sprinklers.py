#Language:Python
#ID:Sprinklers
#QLink:https://www.hackerearth.com/problem/algorithm/sprinklers-7153515e/
#All Accepet
#Author:Amirkhaksar

t = int(input())
for _ in range(t):
    n, q = map(int, input().split())
    a = list(map(int, input().split()))
    r = list(map(int, input().split()))
    l = [0 for i in range(4*n+5)]
    for i in range(n):
        left = a[i]-r[i]+2*n
        right = a[i]+r[i]+2*n+1
        if a[i] > 0:
            left = max(left, 2*n)
        else:
            right = min(right, 2*n)
        l[left] += 1
        l[right] -= 1
    for i in range(1, 4*n+5):
        l[i] += l[i-1]
    for i in range(q):
        k = int(input())
        print(l[k+2*n])
