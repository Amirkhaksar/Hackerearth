'''
Language: python
ID: bb866a75
QLink: https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/supreme-subset-bb866a75/
Author: AmirZoyber
'''
n=list(map(int,input().split()))
l=list(map(int,input().split()))
out=[];dic={}
for i in (l):
  dic.setdefault(i % n[1], []).append(i)

for i in (dic.values()):
    if (len(i)>len(out)):out=sorted(i)
    elif (len(i)==len(out)):out=min(out,sorted(i))
    else:continue

print(len(out))
print(*out)