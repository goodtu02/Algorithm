#from queue import Queue
from collections import deque
import sys

sys.setrecursionlimit(10 ** 6)

n, m = map(int, input().split())
ice = [[0] * m for _ in range(n)]
visit = [[True] * m for _ in range(n)]

for i in range(n):
    ice[i] = list(map(int, input().split()))

count = 0
queue = deque()


def dfs(x, y):
    # if visit[x][y]:
    #   return 0
    visit[x][y] = True
    return 1 + (dfs(x + 1, y) if not visit[x + 1][y] else 0) + (dfs(x - 1, y) if not visit[x - 1][y] else 0) + (
        dfs(x, y + 1) if not visit[x][y + 1] else 0) + (dfs(x, y - 1) if not visit[x][y - 1] else 0)


next_ice = deque()

for i in range(1, n - 1):
    for j in range(1, m - 1):
        if ice[i][j] != 0:
            count += 1
            queue.append((i, j))
        else:
            visit[i][j] = True
year = 0
while True:
    size = len(queue)
    if count == 0:
        print(0)
        exit()
    a = 0
    b = 0
    for _ in range(size):
        x, y = queue.popleft()
        water = 0
        if ice[x - 1][y] == 0:
            water += 1
        if ice[x + 1][y] == 0:
            water += 1
        if ice[x][y + 1] == 0:
            water += 1
        if ice[x][y - 1] == 0:
            water += 1
        current = max(0, ice[x][y] - water)
        if current != ice[x][y]:
            next_ice.append((x, y, current))
        if current != 0:
            visit[x][y] = False
            queue.append((x, y))
            a = x
            b = y
        else:
            count -= 1
    year += 1
    if a == 0 and b == 0:
        continue
    if dfs(a, b) != count:
        print(year)
        exit()
    for i in range(len(next_ice)):
        cdr = next_ice.popleft()
        ice[cdr[0]][cdr[1]] = cdr[2]
