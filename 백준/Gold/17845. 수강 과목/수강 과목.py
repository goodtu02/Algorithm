n, k = map(int, input().split())

value = []
weight = []
for i in range(k):
    a, b = map(int, input().split())
    value.append(a)
    weight.append(b)

dp = [[0] * (n + 1) for i in range(k + 1)]

for i in range(k + 1):
    for j in range(n + 1):
        if i == 0 or j == 0:
            dp[0][0] = 0
            continue
        if weight[i - 1] > j:
            dp[i][j] = dp[i - 1][j]
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1])


print(max(map(max, dp)))
