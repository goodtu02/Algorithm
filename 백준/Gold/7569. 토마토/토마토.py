from queue import Queue
import sys 

m, n, h = map(int, input().split())

box = [[[0] * m for _ in range(n)] for _ in range(h)]

for i in range(h):
    for j in range(n):
        box[i][j] = list(map(int, input().split()))

queue = Queue()

zero = 0
# 1. 초기 상태 확인
for i in range(h):
    for j in range(n):
        for k in range(m):
            if box[i][j][k] == 1:
                queue.put((i, j, k))
            if box[i][j][k] == 0:
                zero += 1
if zero == 0:
    print(0)
    sys.exit()
count = 0

while True:
    cur = queue.qsize()
    if zero == 0:
        print(count)
        sys.exit()
    if cur == 0:
        if zero != 0:
            print(-1)
            sys.exit()

    for i in range(cur):
        cdr = queue.get()
        box[cdr[0]][cdr[1]][cdr[2]] = 1
        if cdr[0] < h - 1:
            if box[cdr[0] + 1][cdr[1]][cdr[2]] == 0:
                queue.put((cdr[0] + 1, cdr[1], cdr[2]))
                box[cdr[0]+1][cdr[1]][cdr[2]] = 1
                zero -= 1
        if cdr[0] > 0:
            if box[cdr[0] - 1][cdr[1]][cdr[2]] == 0:
                queue.put((cdr[0] - 1, cdr[1], cdr[2]))
                box[cdr[0]-1][cdr[1]][cdr[2]] = 1
                zero -= 1

        if cdr[1] < n - 1:
            if box[cdr[0]][cdr[1] + 1][cdr[2]] == 0:
                queue.put((cdr[0], cdr[1] + 1, cdr[2]))
                box[cdr[0]][cdr[1]+1][cdr[2]] = 1
                zero -= 1

        if cdr[1] > 0:
            if box[cdr[0]][cdr[1] - 1][cdr[2]] == 0:
                queue.put((cdr[0], cdr[1] - 1, cdr[2]))
                box[cdr[0]][cdr[1]-1][cdr[2]] = 1
                zero -= 1

        if cdr[2] < m - 1:
            if box[cdr[0]][cdr[1]][cdr[2] + 1] == 0:
                queue.put((cdr[0], cdr[1], cdr[2] + 1))
                box[cdr[0]][cdr[1]][cdr[2]+1] = 1
                zero -= 1

        if cdr[2] > 0:
            if box[cdr[0]][cdr[1]][cdr[2] - 1] == 0:
                queue.put((cdr[0], cdr[1], cdr[2] - 1))
                box[cdr[0]][cdr[1]][cdr[2]-1] = 1
                zero -= 1

    count += 1
