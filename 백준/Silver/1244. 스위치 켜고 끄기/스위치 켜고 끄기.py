p=int(input())

switch = list(map(int,input().split()))

m = int(input())

for i in range(m):
    student, number = map(int,input().split())
    if student == 1:
        for i in range(len(switch)):
            if (i+1)%number==0:
                if switch[i]==0:
                    switch[i]=1
                else:
                    switch[i]=0
    if student == 2:
        number+=-1
        n=0
        while number-n-1>=0 and number+n+1<len(switch) and switch[number-n-1]==switch[number+n+1]:
            n+=1
      
        for i in range(number-n,number+n+1):
            if switch[i]==0:
                switch[i]=1
            else:
                switch[i]=0
        number+=1


for i in range(len(switch)):
    print(switch[i], end=' ')
    if (i + 1) % 20 == 0:
        print()