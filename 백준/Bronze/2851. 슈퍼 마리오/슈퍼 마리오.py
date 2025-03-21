ar=[0]*10

for i in range(0,10):
    ar[i]=int(input())
sum=0
aftersum=0
for i in ar:
    sum=aftersum
    aftersum+=i
    if(aftersum>=100):
        break

minus=aftersum-100
plus=100-sum

if(minus<=plus):
    print(aftersum)
else:
    print(sum)
    

