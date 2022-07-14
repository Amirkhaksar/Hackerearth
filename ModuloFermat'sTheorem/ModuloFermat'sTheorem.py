'''
Language: Python
ID: /modulo-fermats-theorem-728658be
QLink: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/practice-problems/algorithm/modulo-fermats-theorem-728658be/
Author: AmirZoyber
'''
from functools import reduce

p,l=map(int,input().split())

gcd = lambda x,y : x if y==0 else gcd(y,x%y)

def priroot(p):
    s=pf(p-1)
    for i in range(2,p-1):
            for x in s:
                if pow(i,(p-1)//x,p)==1:
                    raise Exception
            return i
pr=priroot(p)

def pf(n):
    s=set();i=2
    while(n>1):
        if n%i==0:
            s.add(i);n/=i
        else:i+=1
    return s
 

def factors(n):    
    return set(reduce(list.__add__, ([i, n//i] for i in range(1, int(pow(n, 0.5) + 1)) if n % i == 0)))
 

def g(x):
    fi=pow(pr,x,p)
    s={1};i=1
    for _ in range((p-1)//x-1):
        i=(i*fi)%p
        s.add(i)
    for i in s:
        if (1-i)%p in s:
            return
    fs.add(x);return

def check(i,s):
    for x in s:
        if (i%x==0):return False
    return True

f=factors(p-1);f.remove(1);f.remove(p-1);fs=set()

for z in f:
    g(z)


div=l//(p-1);r=l%(p-1);c1=1;c2=0

for x in fs:
    n=(p-1)//x;k=r//x+1;s=pf(n)
    for i in range(1,n):
        if check(i,s):
            c1+=1
            if i<k:c2+=1
            
print(div*(p-1-c1)+r-c2)