n=int(input())

ar=[[0]*n for i in range(n)]
for i in range(0,n):
    ar[i]=list(map(int,input().split()))

white=0
blue=0
def conquer(x,y,size):
    global white
    global blue
    flag=True #같은 색 확인
    t = ar[x][y]
    if size==1:
        if t==0:
            white+=1
        else:
            blue+=1
        return
    for i in range(x,x+size):
        for j in range(y,y+size):
            if t!=ar[i][j]:
                flag=False
                break
        if not flag:
            break
    if flag: #더 이상 자르지 않음
        if t==0:
            white+=1
        else:
            blue+=1
        return
    else: #4조각으로 자름
        conquer(x,y,size//2)
        conquer(x+size//2,y,size//2)
        conquer(x,y+size//2,size//2)
        conquer(x+size//2,y+size//2,size//2)

k=ar[0][0]
iff = True
for i in range(0,n):
    for j in range(0,n):
        if k!=ar[i][j]:
            iff=False
            break
    if not iff:
        break    

if iff:
    if k==0:
        print(1)
        print(0)
        exit()
    else:
        print(0)
        print(1)
        exit() 
conquer(0,0,n//2)
conquer(n//2,0,n//2)
conquer(0,n//2,n//2)
conquer(n//2,n//2,n//2)


print(white)
print(blue)