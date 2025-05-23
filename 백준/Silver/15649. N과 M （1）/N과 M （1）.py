n, m = map(int, input().split())

answer = []


def tracking(x):
    global m, answer
    if x + 1 == m:
        print(*answer)
        return
    for i in range(n):
        if i + 1 not in answer:
            answer.append(i + 1)
            tracking(x + 1)
            answer.pop()



for i in range(n):
    answer = [i + 1]
    tracking(0)
