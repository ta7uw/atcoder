N = int(input())
S = input()

left = S.count("(")
right = S.count(")")

plus = 0
ans = ""
for i in range(N):
    if S[i] == "?":
        if left < N // 2:
            ans += "("
            plus += 1
            left += 1

        else:
            ans += ")"
            plus -= 1
            right += 1

    elif S[i] == "(":
        ans += "("
        plus += 1
    else:
        ans += ")"
        plus -= 1

    if i != N - 1 and plus <= 0:
        print(":(")
        exit()
if left == right == N // 2:
    print(ans)
else:
    print(":(")
    exit()
