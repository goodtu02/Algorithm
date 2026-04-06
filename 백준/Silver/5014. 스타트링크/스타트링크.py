from queue import Queue

f,s,g,u,d = map(int,input().split())

#s층에서 g층으로 / 위로 u층, 아래로 d층

queue = Queue()



visit = [False]*(f+1)
queue.put(s)
visit[s]=True
count=0
while True:
    if queue.qsize()==0:
        print("use the stairs")
        exit()
    for i in range(queue.qsize()):
        x=queue.get()
        if x==g:
            print(count)
            exit()
        if x+u>0 and x+u<=f:
            if not visit[x+u]:
                queue.put(x+u)
                visit[x+u]=True
        if x-d>0 and x-d<=f:
            if not visit[x-d]:
                queue.put(x-d)
                visit[x-d]=True
    count+=1

