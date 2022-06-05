'''
Language: Python3.9
ID: passing-marks-efb0d732
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/2-dimensional/practice-problems/algorithm/passing-marks-efb0d732/
Author: AmirZoyber
'''
t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    students = []
    for i in range(n):
        students += [list(map(int, input().split()))]
    students.sort(key=lambda x: x[0] + x[1])
    dp = [0] + [int(1e18)] * n
    for s in students:
        for j in range(n, 0, -1):
            if s[0] >= dp[j - 1]:
                dp[j] = min(dp[j], dp[j - 1] + s[1])
    print(n - dp.count(int(1e18)))