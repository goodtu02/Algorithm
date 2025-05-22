n, s = map(int, input().split())

arr = list(map(int, input().split()))

sum = 0
count = 0


def recursive(x):  # arr의 x번째 원소부터 확인
    global sum, count, s, n
    if n == x:
        return
    for i in range(x + 1, n):
        sum += arr[i]
        if sum == s:
            count += 1
        recursive(i)
        sum -= arr[i]


for i in range(n):  # 첫 원소 지정
    if arr[i] == s:
        count += 1
    sum = arr[i]
    recursive(i)

print(count)
