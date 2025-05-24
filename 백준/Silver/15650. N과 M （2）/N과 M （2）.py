n, m = map(int, input().split())

answer = []


def tracking(x):  # x는 answer원소 개수
    if x == m:
        print(*answer)
        return
    if not answer:
        h = 0
    else:
        h = max(answer)
    for i in range(h, n):
        answer.append(i + 1)
        tracking(x + 1)
        answer.pop()


tracking(0)
