N, C = map(int, input().split())
xy = []
for _ in range(N):
    xy.append(tuple(map(int, input().split())))
ans = 0
cal_sum_A = [0 for _ in range(N)]
cal_sum_A[0] = xy[0][1] - xy[0][0]
for i in range(1, N):
    cal_sum_A[i] += cal_sum_A[i - 1] + xy[i][1] - xy[i][0] + xy[i - 1][0]

cal_sum_B = [0 for _ in range(N)]
cal_sum_B[N - 1] = xy[N - 1][1] - (C - xy[N - 1][0])
for i in range(N - 2, -1, -1):
    cal_sum_B[i] += cal_sum_B[i + 1] + xy[i][1] - (C - xy[i][0]) + (C - xy[i + 1][0])

# O -> A
max_cal_A = [0 for _ in range(N)]
max_cal_A[0] = cal_sum_A[0]
for i in range(1, N):
    max_cal_A[i] = max(max_cal_A[i - 1], cal_sum_A[i])
ans = max(ans, max_cal_A[N-1])
# O -> B
max_cal_B = [0 for _ in range(N)]
max_cal_B[N-1] = max(max_cal_B[N-1], cal_sum_B[N-1])

for i in range(N-2, -1, -1):
    max_cal_B[i] = max(max_cal_B[i+1], cal_sum_B[i])
ans = max(ans, max_cal_B[0])
# O -> B -> O -> A
for i in range(1, N-1):
    cal = 0
    cal += cal_sum_B[-i]
    cal -= (C-xy[-i][0])
    cal += max_cal_A[N-i-1]
    ans = max(ans, cal)
# 0 -> A -> O -> B
for i in range(1, N):
    cal = 0
    cal += cal_sum_A[i-1]
    cal -= xy[i-1][0]
    cal += max_cal_B[-(N-i)]
    ans = max(ans, cal)
print(ans)








