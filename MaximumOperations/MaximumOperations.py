'''
Language: Python
ID: /contest-bw-sonika-and-rishika-216a7b6d
QLink: https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/practice-problems/algorithm/contest-bw-sonika-and-rishika-216a7b6d/
Author: AmirZoyber
'''
def swap(a,b): 
    temp=a 
    a=b 
    b=temp 

def xnor(a, b): 

    if (a < b):swap(a, b) 
    if (a == 0 and b == 0) :return 1
    a_rem = 0 
    b_rem = 0 
    count = 0
    xnornum = 0 
    while (a!=0) : 
        a_rem = a & 1
        b_rem = b & 1 
        if (a_rem == b_rem):      
            xnornum |= (1 << count) 
        count=count+1
        a = a >> 1
        b = b >> 1
    return xnornum
 
t=int(input())
while(t):
    a,b,n=input().split()
    a=int(a);b=int(b);n=int(n)
    if(n%3==1):print(a)
    if(n%3==2):print(b)
    if(n%3==0):
        a1=(a^b);a2=xnor(a, b)
        print(max(a1,a2))
    t=t-1