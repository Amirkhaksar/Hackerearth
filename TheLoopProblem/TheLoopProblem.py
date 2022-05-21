'''
Language: python
ID: loop-problem-db615209
QLink: https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/loop-problem-db615209/
Author: AmirZoyber
'''
def count(a, b, base):
    count = 0;n=base*2
    x = a + (n - a % n);y = b + (n - b % n)
    count += min(x - a, base)
    count -= min(y - b - 1, base) 
    count += (y - x) // 2
    return count

mod = 10 ** 9 + 7
for _ in range(int(input())):
    a,b,c,d = [int(x) for x in input().split()]
    ans = 0
    diff1, diff2 = b - a + 1, d - c + 1
    for j in range(1, max(b, d).bit_length() + 1):
        num = pow(2,j-1)
        on1 = count(a,b,num)
        on2 = count(c,d,num)
        off1 = diff1-on1
        off2 = diff2-on2 
        ans += (on1*off2 + on2*off1) % mod*(num % mod)
        ans %= mod
    print(ans)