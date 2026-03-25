
n,g=map(str,input().split())

n=int(n)
s=[]

for i in range(n):
    s.append(str(input()))

s=set(s)

s=list(s)

if g=='Y':
    print(len(s))
elif g=='F':
    print(len(s)//2)
else:
    print(len(s)//3)

