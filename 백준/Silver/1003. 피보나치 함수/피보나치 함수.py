import sys

#n=int(input())
n=int(sys.stdin.readline())
m=[]
for i in range(0,n) :
    k=int(sys.stdin.readline())
    m.append(k)

zero=[0]*41
one=[0]*41

zero[0]=1
zero[1]=0
one[0]=0
one[1]=1

for i in range(2,41):
    zero[i]=zero[i-1]+zero[i-2]
    one[i]=one[i-1]+one[i-2]

for i in range(0,n):
    print(zero[m[i]], one[m[i]])
    
