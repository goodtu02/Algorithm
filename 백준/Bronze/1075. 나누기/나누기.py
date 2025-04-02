n=int(input())

f=int(input())

remain = n%100

n-=remain

while True:
    if n%f==0:
        break
    n+=1

remain = n%100
l = str(remain)
if len(l)==0:
    print("00")
elif len(l)==1:
    print('0'+l)
else:
    print(l)



