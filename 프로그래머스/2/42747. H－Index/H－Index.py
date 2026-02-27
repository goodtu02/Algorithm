def solution(citations):
    answer = 0
    for i in range(max(max(citations),len(citations))): #from 0 to n
        count = 0
        for k in citations: #count h
            if k>=i:
                count+=1
        if count >= i:
            answer=i
    return answer