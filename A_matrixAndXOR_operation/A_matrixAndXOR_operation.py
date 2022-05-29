'''
Language: Python
ID: matrix-and-xor-operation-a2e19185
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/matrix-and-xor-operation-a2e19185/
Author: AmirZoyber
'''
for _ in range(int(input())):
    n, m, k = map(int, input().split())
    bl = False
    for i in range(n + 1):
        if (2 * i - n != 0 and (k - m * (n - i)) % (2 * i - n) == 0 and 0 <= (k - m * (n - i)) / (2 * i - n) <= m):
            bl=True
    print("Yes") if (bl) else print("No")
