import math 

n=int(input())

a=list(map(int, input().split()))
b,c=map(int, input().split())
sum=0

for i in a:
    if i-b>0:
        sum+=math.ceil((i-b)/c)
        sum+=1
    else:
        sum+=1
print(sum)
