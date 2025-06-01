n, t = map(int, input().split())

weight = []
value = []

for i in range(n):
    a, b = map(int, input().split())
    weight.append(a)
    value.append(b)

# t를 넘지 않으면서 value가 최대

dp = [[0] * (t + 1) for i in range(n + 1)]

for i in range(n + 1):
    for j in range(t + 1):
        if i == 0 or j == 0:
            dp[i][j] = 0
            continue
        if weight[i - 1] > j:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1])

print(max(map(max, dp)))
