t=int(input())
answer = [0]*t
for k in range(t):
    n=int(input())
    rank=list(map(int,input().split()))
    ar=[0]*201
    score=[0]*201
    
    for i in rank:
        ar[i]+=1
    #rank를 순회하다가 유효한 팀만 점수 부여 ar==6
    point = 1
    count=[0]*201
    fifth=[0]*201
    for i in rank:
        if ar[i]==6:
            count[i]+=1
            if count[i]<5:
                score[i]+=point
            if count[i]==5:
                fifth[i]=point
            point+=1
    m=600000000
    for i in range(201):
        if score[i]<m and score[i]!=0:
            m=score[i]
    joint=[] 
    for i in range(201):
        if score[i]==m:
            joint.append(i)
    m=600000000

    for i in joint:
        if fifth[i]<m and fifth[i]!=0:
            m=fifth[i]

    for i in joint:
        if fifth[i]==m:
            answer[k]=i
            break

for i in answer:
    print(i)


