'''
Language: Python
ID: jp-and-the-escape-planapprox
QLink: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/approximate/jp-and-the-escape-planapprox/
Author: AmirZoyber
'''
from collections import deque # صف

def escape(x, y, max_x, max_y, max_jump, adjacency, visited, pars):
    if x in (0, max_x - 1) or y in (0, max_y - 1):
        return x, y
    jumps = ((1, 0), (-1, 0), (0, 1), (0, -1))
    for jump_x, jump_y in jumps:
        nx = x + jump_x;ny = y + jump_y
        nj = adjacency[nx][ny] - adjacency[x][y]
        if (0 <= nx < max_x and 0 <= ny < max_y and not visited[nx][ny] and 0 <= nj <= max_jump):
            visited[nx][ny] = True;pars[(nx, ny)] = (x, y)
            return escape(nx, ny, max_x, max_y, max_jump, adjacency, visited, pars)
    return False

n, m = map(int, input().strip().split())
grid = [list(map(int, input().strip().split())) for _ in range(n)]
dx, dy, j = map(int, input().strip().split())
dx -= 1;dy -= 1
reached = [[False] * m for _ in range(n)]
reached[dx][dy] = False
parents = {(dx, dy): None}
res = escape(dx, dy, n, m, j, grid, reached, parents)
if res:
    ans = deque()
    p = res
    while p:
        ans.appendleft(p)
        if parents[p]:p = parents[p]
        else:break
    print('YES')
    print(len(ans))
    for u, v in ans:
        print(u + 1, v + 1)
else:print('NO')