#Language:python
#ID:disk-tower
#QLink:https://www.hackerearth.com/problem/algorithm/disk-tower-b7cc7a50/
#All Accepet
#Author:Amirkhaksar

from heapq import heappop, heappush, heapify

n = int(input())

l = list(map(int, input().split()))

heap = []

heapify(heap)

m = n

for i in range(n):

    heappush(heap, -1 * l[i])

    try:

        while(-1*heap[0] == m):

            print(m, end=" ")

            m -= 1

            heappop(heap)

    except:

        pass

    print("\n")
