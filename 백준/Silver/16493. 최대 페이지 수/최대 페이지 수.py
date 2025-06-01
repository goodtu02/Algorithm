n, m = map(int, input().split())

weight = []
value = []
max_value = 0
for i in range(m):
    a, b = map(int, input().split())
    weight.append(a)
    value.append(b)
items = list(zip(weight, value))
items.sort(key=lambda x: x[1] / x[0], reverse=True)
weight = [w for w, v in items]
value = [v for w, v in items]


def cal(x, w, cur_value):  # upper_bound 계산
    global value, weight, n, m
    bound = cur_value
    for i in range(x, m):
        w += weight[i]
        bound += value[i]
        if w > n:
            bound -= value[i]
            bound += (value[i] / weight[i]) * (n - (w - weight[i]))  # 남은 물건 쪼개기
            break
    return bound


def tracking(x, w, bound, cur_value):  # x : item num
    global weight, max_value, value, n, m
    if bound < max_value:
        return
    for i in range(x + 1, m):
        bound_exclude = cal(i + 1, w, cur_value)
        tracking(i, w, bound_exclude, cur_value)  # 물건 안넣기
        if w + weight[i] > n:
            continue
        cur_value += value[i]
        w += weight[i]
        bound_include = cal(i + 1, w, cur_value)
        max_value = max(max_value, cur_value)
        tracking(i, w, bound_include, cur_value)  # 물건 넣기
        cur_value -= value[i]
        w -= weight[i]


tracking(-1, 0, cal(0, 0, 0), 0)
print(max_value)
