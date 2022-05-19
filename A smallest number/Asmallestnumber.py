"""
#Language:Python
#ID:A smallest number
#QLink:https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/smallest-number-4-7ee4ca9a/
#All Accepet
#Author:Amirkhaksar
"""



def multiplyList(myList):
    # Multiply elements one by one
    result = 1
    for x in myList:
        result = result * x
    return result


t = int(input())
while t > 0:
    t -= 1
    n = int(input())
    for i in range(1, 10 ** 6):
        if '0' not in str(i) and multiplyList(map(int, str(i))) >= n - len(str(i)) + sum(map(int, str(i))):
            print('1' * (n - len(str(i))), i, sep='')
            break