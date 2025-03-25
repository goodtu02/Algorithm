t=int(input())
n=[0]*t
m=[0]*t

for i in range(t):
    n[i],m[i]=map(int,input().split())
 
dp=[0]*(max(m)+1)

dp[0]=1
dp[1]=1
for i in range(1,len(dp)):
    dp[i]=i*dp[i-1]

ans=[]
for i in range(t):
    
    ans.append(int(dp[m[i]]/(dp[m[i]-n[i]]*dp[n[i]])))

for _ in ans:
    print(_)


