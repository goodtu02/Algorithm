
#최종 점수가 같은 경우, 풀이를 제출한 횟수가 적은 팀의 순위가 높다. 
#최종 점수도 같고 제출 횟수도 같은 경우, 마지막 제출 시간이 더 빠른 팀의 순위가 높다. 

#팀 당 문제 별 점수 합산 같은 문제는 큰 점수 사용
T=int(input())

for _ in range(T):
    n,k,t,m= map(int,input().split())
    list = [[0]*k for _ in range(n)] #팀 당 문제별 점수
    final = [[0]*4 for _ in range(n)] #팀 당 최종 점수, 풀이 제출 횟수, 마지막 제출 시간
    for p in range(m):
        i,j,s = map(int,input().split())
        if list[i-1][j-1]<=s:
            list[i-1][j-1]=s 
        final[i-1][1]+=1 #제출횟수
        final[i-1][2]=p #제출시간

    for p in range(n): #점수 합
        for o in range(k):
            final[p][0]+=list[p][o]
    
    for p in range(1,n+1): #팀 ID
        final[p-1][3]=p

    sorted_list = sorted(final, key=lambda x:(-x[0],x[1],x[2]))
    for p in range(n):
        if sorted_list[p][3] == t:
            print(p+1)
            break
