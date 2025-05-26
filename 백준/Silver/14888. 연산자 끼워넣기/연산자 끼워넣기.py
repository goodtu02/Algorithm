n = int(input())

num = list(map(int, input().split()))

operator = list(map(int, input().split()))  # + - * /


max_num = -1000000000
min_num = 1000000000

count = 0

sum_before = []


def calculate(loc, idx, sum):  # number, operator
    global op, num
    if idx == 0:
        return sum + num[loc + 1]
    if idx == 1:
        return sum - num[loc + 1]
    if idx == 2:
        return sum * num[loc + 1]
    if idx == 3:
        if sum < 0:
            return -(-sum // num[loc + 1])
        else:
            return sum // num[loc + 1]


def tracking(x, sum):  # x is depth of tree
    global min_num, max_num, n, sum_before
    if x == n - 1:
        if sum < min_num:
            min_num = sum
        if sum > max_num:
            max_num = sum
        return
    for i in range(4):
        if operator[i] == 0:
            continue
        operator[i] -= 1
        tracking(x + 1, calculate(x, i, sum))
        operator[i] += 1


tracking(0, num[0])

print(max_num, min_num)
