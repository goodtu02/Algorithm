n = int(input())

queen = [-1] * n

count = 0


def check(x, y):  # 상하 대각선 확인
    for i in range(n):
        if queen[i] == x or abs(queen[i] - x) == abs(i - y):
            return False
        if queen[i] == -1:  # 더 확인할 필요 없음
            break
    return True


def tracking(m):
    global queen, n, count
    if n == m:
        count += 1
        return
    for i in range(n):
        if check(i, m):  # promising
            queen[m] = i
            tracking(m + 1)  # pruning
    queen[m] = -1
    return


tracking(0)

print(count)
