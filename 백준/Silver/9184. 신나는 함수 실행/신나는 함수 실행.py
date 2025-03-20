
A=[]
B=[]
C=[]
rec={}
a,b,c=map(int, input().split())
ans={}

def w(a,b,c):
    
    if (a, b, c) in rec:
        return rec[(a,b,c)]
    if a <= 0 or b <= 0 or c <= 0:
        rec[(a,b,c)]=1
        return 1
    elif a > 20 or b > 20 or c > 20:
        rec[(a,b,c)]=w(20,20,20)
        return rec[(a,b,c)]

    elif a < b and b < c:
        rec[(a,b,c)]=(w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c))
        return rec[(a,b,c)]

    else:
        rec[(a,b,c)]=(w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1))
        return rec[(a,b,c)]
    
while True:
    A.append(a)
    B.append(b)
    C.append(c)
    ans[(a,b,c)]=w(a,b,c)
    a,b,c=map(int, input().split())
    if(a==-1 and b==-1 and c==-1): 
        break
   


for i in range(0,len(A)):
   print("w({}, {}, {}) = {}".format(A[i],B[i],C[i],ans[(A[i],B[i],C[i])]))

