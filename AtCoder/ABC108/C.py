N, K = map(int, input().split())

if K % 2 != 0:
    num = [i for i in range(1, N+1) if i % K ==0]
    print(len(num)**3)
else:
    num = [i for i in range(1, N+1) if i % K == 0]
    half_num = [i for i in range(1, N+1) if i % K == (K/2)]
    print((len(num))**3 + len(half_num)**3)
