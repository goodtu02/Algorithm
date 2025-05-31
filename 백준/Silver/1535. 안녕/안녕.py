n = int(input())

weight = list(map(int,input().split()))
value = list(map(int,input().split()))

dp = [[0]*(100) for i in range(n+1)]

for i in range(n+1):
    for j in range(100): #한계 weight
        if i==0 or j==0:
            dp[i][j]=0
            continue
        if weight[i-1]>j:
            dp[i][j]=dp[i-1][j]
        else:
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i-1]]+value[i-1])

print(max(map(max,dp)))