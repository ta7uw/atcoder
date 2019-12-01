N = int(input())
t_list = list(map(int, input().split()))
v_list = list(map(int, input().split()))
t_sum = sum(t_list)
v_max = [0.0] * (2 * t_sum + 1)

t_i = 0
v_i = 0
t = t_list[t_i]
v = v_list[v_i]
time = 0
for i in range(1, 2 * t_sum + 1):
    time += 0.5
    if time >= t:
        time = 0
        t_i += 1
        v_i += 1
        if t_i >= N:
            break
        t = t_list[t_i]
        v_max[i] = min(min(v, v_list[v_i]), v_max[i - 1] + 0.5)
        v = v_list[v_i]
        continue
    v_max[i] = min(v, v_max[i - 1] + 0.5)

t_i = N - 1
v_i = N - 1
t = t_list[t_i]
v = v_list[v_i]
v_max[-1] = 0
time = 0
for i in range(2 * t_sum - 1, -1, -1):
    time += 0.5
    if time >= t:
        t_i -= 1
        v_i -= 1
        if t_i < 0:
            break
        t = t_list[t_i]
        v = v_list[v_i]
        time = 0
    if v_max[i] > v_max[i + 1] + 0.5:
        v_max[i] = v_max[i + 1] + 0.5

ans = 0
for i in range(len(v_max) - 1):
    ans += (v_max[i] + v_max[i + 1]) * 0.25
print(ans)
