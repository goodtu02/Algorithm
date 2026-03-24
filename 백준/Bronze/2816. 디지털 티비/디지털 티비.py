n=int(input())
c=[]
for i in range(n):
    c.append(input())
count=0
ans=""
for i in range(n):
    count+=1
    if c[i]=="KBS1":
        for j in range(count-1):
            ans+="1"
        while(c[0]!="KBS1"):
            c[i-1],c[i] = c[i],c[i-1]
            i-=1
            ans+="4"
        break
count=0
for i in range(n):
    if c[1]=="KBS2":
        break
    count+=1
    if c[i]=="KBS2":
        for j in range(count-1):
            ans+="1"
        while(c[1]!="KBS2"):
            c[i-1],c[i] = c[i],c[i-1]
            ans+="4"
            i-=1
        break
print(ans)