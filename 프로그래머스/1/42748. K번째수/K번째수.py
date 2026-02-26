def solution(array, commands):
    answer = []
    for l in commands:
        i=l[0]
        j=l[1]
        k=l[2]
        ar = []
        for p in range(i,j+1):
            ar.append(array[p-1])
        ar.sort()
        answer.append(ar[k-1])
    return answer