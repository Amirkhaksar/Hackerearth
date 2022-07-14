'''
Language: Python
ID: /count-triples-d930e6b4
QLink: https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practice-problems/algorithm/count-triples-d930e6b4/
Author: AmirZoyber
'''
for _ in range(int(input())):
    x,y=input().strip().split()
    n=int(x);k=int(y)
    a=0;count=0
    t=(n+k)//2+1;b=(n-t)//2
    if (n%2==0 and k%2==0) or (n%2!=0 and k%2!=0):a=(n-k)//2-1
    else:a=(n-k)//2

    if a>n//3:
        j=n//3+1;i=j+1
        a1=((3*j)-n+2)//2;a2=((3*i)-n+2)//2
        n2=(a-j+1)//2;n1=(a-j+1)-n2
        count+=(n1*((2*a1)+(n1-1)*3))//2+(n2*((2*a2)+(n2-1)*3))//2

    if (n - t) % 2 == 0 and b > 1:
        w = b - 1
        count += ((w * (w + 1)) // 2) * 2;count += b
    else:
        if b > 1:count += ((b * (b + 1)) // 2) * 2
        else:
            if b == 1:
                if t != (n - 2):count += 2
                else:count += 1
            else:count += 0
    if n % 3 == 0 and n // 3 > k:count += 1
    print(count)