'''
Language: python
ID: micro-and-sweet-distribution
QLink: https://www.hackerearth.com/practice/data-structures/arrays/multi-dimensional/practice-problems/algorithm/micro-and-sweet-distribution/
Author: AmirZoyber
'''
num = int(input())
for i in range(num):
 
    n, m = map(int, input().split())
    s = list(map(int, input().split()))
    d = list(map(int, input().split()))
 
    if ((s[0] == 1) and (s[1] == 1)):             #   1 - 1
        if ((d[0] % 2) == 0):
            print("Over") if (d[0] == n) else print("Back") if (d[1] == 1) else print("Left")
        else:
            print("Over") if (d[0] == n) else print("Back") if (d[1] == m) else print("Right")

 
    elif ((s[0] == 1) and (s[1] == m)):             #   1 - m
        if ((d[0] % 2) == 1):
            print("Over") if (d[0] == n) else print("Back") if (d[1] == 1) else print("Left")
        else:
            print("Over") if (d[0] == n) else print("Back") if (d[1] == m) else print("Right")


    elif ((s[0] == n) and (s[1] == 1)):             #   n - 1
        if ((d[0] % 2) != (s[0] % 2)):
            print("Over") if (d[0] == 1) else print("Front") if (d[1] == 1) else print("Left")
        else:
            print("Over") if (d[0] == 1) else print("Front") if (d[1] == m) else print("Right")
 
    elif ((s[0] == n) and (s[1] == m)):             #   n - m
        if ((d[0] % 2) == (s[0] % 2)):
            print("Over") if (d[0] == 1) else print("Front") if (d[1] == 1) else print("Left")
        else:
            print("Over") if (d[0] == 1) else print("Front") if (d[1] == m) else print("Right")
 
    print("\n")
