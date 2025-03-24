
n = int(input())

dp=[0]*21
def fac(n):
    if dp[n]!=0:
        return dp[n]
    if n==0 or n==1:
        dp[n]=1
        return 1
    else:
        dp[n]=dp[n-1]*n
        return fac(n-1)*n

dp[0]=1
for i in range(0,n):
    fac(n)
print(dp[n])

