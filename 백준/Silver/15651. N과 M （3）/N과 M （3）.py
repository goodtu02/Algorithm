n, m = map(int, input().split())

answer = []


def tracking(x):  # x는 answer의 원소 개수
    if x == m:
        print(*answer)
        return
    for i in range(n):
        answer.append(i + 1)
        tracking(x + 1)
        answer.pop()


tracking(0)
