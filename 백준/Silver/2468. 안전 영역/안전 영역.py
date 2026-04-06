n = int(input())
import sys

sys.setrecursionlimit(1000000)
area = [[0] * n for _ in range(n)]


def dfs(x, y):
    if visit[x][y]:
        return None
    visit[x][y] = True
    if x > 0:
        dfs(x - 1, y)
    if y > 0:
        dfs(x, y - 1)
    if x < n - 1:
        dfs(x + 1, y)
    if y < n - 1:
        dfs(x, y + 1)
    return None


for i in range(n):
    area[i] = list(map(int, input().split()))

safe = 0
for k in range(101):
    for i in range(n):
        for j in range(n):
            area[i][j] -= 1

    visit = [[False] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if area[i][j] <= 0:
                visit[i][j] = True
    temp = 0
    flag = False
    for i in range(n):
        for j in range(n):
            if not visit[i][j]:
                flag = True
    if not flag:
        temp = 1
        safe = max(safe, temp)
        continue
    for i in range(n):
        for j in range(n):
            if not visit[i][j]:
                temp += 1
                dfs(i, j)

    safe = max(safe, temp)

print(safe)
