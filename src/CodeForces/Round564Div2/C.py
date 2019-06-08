N = int(input())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))

getting = [0] * (N + 1)
flg = False
for i in range(N):
    b = b_list[i]
    getting[b] = i + 1
    if flg and b_list[i - 1] != b - 1:
        flg = False

    if b == 1:
        flg = True

if flg:
    start = b_list[-1] + 1
    step = 0
    for i in range(start, N + 1):
        if getting[i] > step:
            flg = False
            break
        step += 1
    if flg:
        print(N - start + 1)
        exit()

ans = 0
for i in range(1, N + 1):
    if getting[i] > i - 1 and ans < getting[i] - (i - 1):
        ans = getting[i] - (i - 1)
print(N + ans)
