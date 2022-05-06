'''
Language: python
ID: card-sum-6710882a
QLink: https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/card-sum-6710882a/
Author: AmirZoyber
'''
test_case = int(input())
for _ in range(test_case):
    n, mx = map(int,input().split())
    sumT = sum(map(int,input().split(" ", n-1)))
    if (sumT<=mx):print(1)
    else:
        count = 0
        while (sumT > mx):
            count+=sumT//mx
            sumT%=mx
        count+=1
        print(count)

