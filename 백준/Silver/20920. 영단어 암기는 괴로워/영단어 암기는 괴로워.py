import sys

input = sys.stdin.readline

n,m = map(int,input().split())
list = {}

for _ in range(n):
    word = input().rstrip()
    if len(word)>=m:
        if word in list:
            list[word]+=1
        else:
            list[word]=1

sorted_list=sorted(list.items(), key=lambda item:(-item[1],-len(item[0]),item[0]))
for i in sorted_list:
    print(i[0])