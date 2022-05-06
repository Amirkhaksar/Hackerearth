lk = list(map(int, input().split()))
n, k = lk[0], lk[1]
a = list(map(int, input().split()))
a.sort()
diff = n-k
a = a[:diff]
print(sum(a))
