# 1. 현재 칸 청소
# 2. 주변 4칸 중 청소칸 없으면 방향 유지한 채로 한 칸 뒤로
# 3. 주변 4칸이 깨끗하면 반시계 방향 90도 회전 -> 앞쪽을 청소해야 하면 전진
# 벽이면 못 감, 벽은 청소 할 필요 없음

n, m = map(int, input().split())
r, c, d = map(int, input().split())

room = [[0] * m for _ in range(n)]
clean = [[0] * m for _ in range(n)]
for i in range(n):
    room[i] = list(map(int, input().split()))
for i in range(n):
    for j in range(m):
        clean[i][j]=room[i][j]
count = 0


def dfs(x, y):
    global d, count
    if clean[x][y] == 0:  # 1
        clean[x][y] = 1
        count += 1
    if clean[x + 1][y] == 1 and clean[x - 1][y] == 1 and clean[x][y + 1] == 1 and clean[x][y - 1] == 1:  # 2
        if d == 0:
            if room[x + 1][y] == 0:
                dfs(x + 1, y)
            else:
                print(count)
                exit()
        elif d == 1:
            if room[x][y - 1] == 0:
                dfs(x, y - 1)
            else:
                print(count)
                exit()
        elif d == 2:
            if room[x - 1][y] == 0:
                dfs(x - 1, y)
            else:
                print(count)
                exit()
        elif d == 3:
            if room[x][y + 1] == 0:
                dfs(x, y + 1)
            else:
                print(count)
                exit()
    else:  # 3
        while True:
            if d == 0:
                d = 3
                if clean[x][y - 1] == 0:
                    dfs(x, y - 1)
                    break
            elif d == 1:
                d = 0
                if clean[x - 1][y] == 0:
                    dfs(x - 1, y)
                    break
            elif d == 2:
                d = 1
                if clean[x][y + 1] == 0:
                    dfs(x, y + 1)
                    break
            elif d == 3:
                d = 2
                if clean[x + 1][y] == 0:
                    dfs(x + 1, y)
                    break

dfs(r, c)
print(count)
