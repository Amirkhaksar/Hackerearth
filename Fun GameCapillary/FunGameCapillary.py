#Language:python
#ID:fun-game
#QLink:https://www.hackerearth.com/problem/algorithm/fun-game-91510e9f/
#All Accepet
#Author:Amirkhaksar

def funGame (arr):
    lst = []
    index = -1
    i = 0
    tempArr =list(arr)
    while i < len(tempArr) and index >= -len(tempArr):
        a = tempArr[i]
        b = tempArr[index]
        if b > a:
            lst.append(2)
            i += 1
        elif a > b:
            lst.append(1)
            index -= 1
        else:
            lst.append(0)
            i += 1
            index -= 1
 
    return lst
 
n = int(input())
arr = map(int, input().split())
 
out_ = funGame(arr)
print (' '.join(map(str, out_)))