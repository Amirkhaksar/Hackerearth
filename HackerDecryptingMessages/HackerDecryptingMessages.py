'''
Language: Python
ID: /hacker-with-prime-bebe28ac
QLink: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/hacker-with-prime-bebe28ac/
'''
def check (x):
    if (x < 4): return False
    y = x; vec = []
    while (x != 1):
        xx = spf [x]
        vec.append (xx)
        while (x % xx == 0): x //= xx
    for i in range (len (vec)):
        for j in range (i, len (vec)):
            if (y % (vec [i] * vec [j]) == 0 and mk [y // (vec [i] * vec [j])]): return True
    return False

MX = 1000001
spf = [0] * MX
mk = bytearray ([False]) * MX
for i in range (2, MX):
        if (spf [i] == 0):
            for j in range (i, MX, i):
                if (spf [j] == 0): spf [j] = i
n, q = map (int, input().split())
a = list (map (int, input().split ()))
for x in a: mk [x] = True
for i in range (2, MX):
    if (mk [i]):
        j = i
        while j < MX:
                mk [j] = True
                j *= i
mk [1] = True
for q_ in range (q):
    x = int (input())
    if check (x): print ("YES")
    else: print ("NO")
 
