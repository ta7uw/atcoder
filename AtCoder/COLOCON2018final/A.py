N = int(input())
S = input()

if S.count("B") == 0:
    tmp = N * len(S)
    print(tmp * (tmp + 1) // 2)
    exit()

if N == 1:
    prev_a = 0
    ans = 0
    for s in S:
        if s == "A":
            if prev_a == 0:
                ans += 1
                prev_a += 1
            else:
                ans += prev_a + 1
                prev_a += 1
        else:
            prev_a = 0
    print(ans)
else:
    first = S[0]
    last = S[-1]
    if first == "A" and last == "A":
        start_b = S.index("B")
        rev_b = S[::-1].index("B")

        prev_a = 0
        ans = 0
        for s in S[start_b:-rev_b]:
            if s == "A":
                if prev_a == 0:
                    ans += 1
                    prev_a += 1
                else:
                    ans += prev_a + 1
                    prev_a += 1
            else:
                prev_a = 0
        tmp1 = start_b * (start_b + 1) // 2
        tmp2 = rev_b * (rev_b + 1) // 2
        tmp3 = (start_b + rev_b) * (start_b + rev_b + 1) // 2
        print(N * ans + tmp1 + tmp2 + (N - 1) * tmp3)

    else:
        prev_a = 0
        ans = 0
        for s in S:
            if s == "A":
                if prev_a == 0:
                    ans += 1
                    prev_a += 1
                else:
                    ans += prev_a + 1
                    prev_a += 1
            else:
                prev_a = 0
        print(ans * N)
