T = int(input())
for t in range(T):
    N, K = map(int, input().split())
    cnt = 0
    while N != 0:
        if N - 1 == 0:
            N -= 1
        elif N % K == 0:
            N //= K
        else:
            tmp = N % K
            N -= tmp
            cnt += tmp
            continue
        cnt += 1
    print(cnt)
