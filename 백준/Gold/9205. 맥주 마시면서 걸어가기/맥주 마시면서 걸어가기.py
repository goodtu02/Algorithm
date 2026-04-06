from queue import Queue

t=int(input())

for i in range(t):

    n=int(input())
    house=list(map(int,input().split()))
    conv = [0]*n
    for j in range(n):
        conv[j]=list(map(int,input().split()))
    fest=list(map(int,input().split()))
#집에서 첫번째 편의점까지, n번째 편의점에서 n+1번째 편의점으로, n+1 편의점에서 페스티벌까지 갈 수 있나
#50미터 갈 때마다 한 병 소모 편의점에 들릴 때 마다 20병
    visit=[]
    queue = Queue()
    queue.put(house)
    visit.append((house[0]+32768,house[1]+32768))

    while True:
        if queue.qsize()==0:
            print("sad")
            break
        leng = queue.qsize()
        flag=True
        for k in range(leng):
            cdr = queue.get()

            x=cdr[0]
            y=cdr[1]

            if abs(fest[0]-x)+abs(fest[1]-y)<=1000:
                flag=False
                break

            for j in conv: #현재 위치에서 거리가 1000m 이하인 편의점 넣기
                if abs(j[0]-x)+abs(j[1]-y)<=1000 and (j[0]+32768,j[1]+32768) not in visit:
                    queue.put(j)
                    visit.append((j[0] + 32768, j[1] + 32768))

        if not flag:
            print("happy")
            break







    
    
