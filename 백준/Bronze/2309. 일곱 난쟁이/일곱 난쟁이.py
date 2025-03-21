from itertools import combinations

ar=[]

for i in range(9):
    ar.append(int(input()))

combi = list(combinations(ar, 7))
sum=0
for i in combi:
    
    sum=0
    for j in i:
        sum+=j
    if sum==100:
        ar = sorted(i)
        for k in ar:
            print(k)
        break