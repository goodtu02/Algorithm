n, k = map(int, input().split())

w = []  # weight
p = []  # price
for i in range(n):
    a, b = map(int, input().split())
    w.append(a)
    p.append(b)

dp = [[0] * (k + 1) for i in range(n + 1)]


for i in range(n + 1):  # i-1번째 물건까지
    for j in range(k + 1):  # 가방 한도
        if i == 0 or j == 0:
            dp[i][j] = 0
            continue
        if w[i - 1] > j:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1])
            # (물건 안넣기, 이전 상태에서 물건 넣기)

print(max(map(max, dp)))
