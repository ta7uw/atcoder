H, W = map(int, input().split())
d = {0: 1, 1: 1, 2: 1, 3: 1, 4: 1, 5: 1, 6: 2, 7: 2, 8: 3, 9: 4}

if H == 1 or W == 1:
    if H == 1:
        A = list(map(int, input().split()))
    else:
        A = [int(input()) for _ in range(H)]
    M = max(A)
    n = len(A)
    ans = float('inf')
    if M == 0:
        print('Yes', 0)
    elif 5 in A:
        idx = [k for k, x in enumerate(A) if x == 5]
        for i in idx:
            if i == 0 or i == n - 1:
                ans = min(ans, d[M])
            else:
                M1, M2 = max(A[:i]), max(A[i + 1:])
                ans = min(ans, d[M1] + d[M2] - 1)
        print('Yes', ans)
    else:
        print('No')
    exit()

all = []
for i in range(H):
    tmp = list(map(int, input().split()))
    all.extend(tmp)

if max(all) == 0:
    print("Yes", 0)
    exit()

if all.count(5) == 0:
    print("No")
    exit()

if all.count(9) >= 1:
    print("Yes", 4)
    exit()

if all.count(8) >= 1:
    print("Yes", 3)
    exit()

if all.count(7) >= 1 or all.count(6) >= 1:
    print("Yes", 2)
    exit()

print("Yes", 1)
