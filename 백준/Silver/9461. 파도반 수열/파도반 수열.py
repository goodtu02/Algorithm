n=int(input())

arr=[0]*n

for i in range(0,n):
    arr[i]=int(input())

dp=[0]*101

dp[0]=1
dp[1]=1
dp[2]=1
for i in range(3,101):
    dp[i]=dp[i-2]+dp[i-3]

for i in range(0,n):
    print(dp[arr[i]-1])