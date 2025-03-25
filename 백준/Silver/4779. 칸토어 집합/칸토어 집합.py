
ans=[]
inp=[]


def cantor(start,end):
    if end-start==1: return
    t = int((end-start)/3)
    for i in range(start+t,end-t):
        ans[i]=0
    cantor(start,start+t)
    cantor(end-t,end)
while True:
    try:
        inp.append(3**int(input()))
    except:
        break

for i in inp:
    ans=[1]*(i)
    cantor(0,i)
    for i in ans:
        if i==0: print(' ',end="")
        else: print('-',end="")
    print()
