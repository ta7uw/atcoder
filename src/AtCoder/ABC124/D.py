N, K = map(int, input().split())
S = input()

left = 0
right = 0
ans = 0
remain = K
S += "?"
if S[0] == "0":
    remain -= 1

while left < N:
    while right < N and remain >= 0:
        if S[right] == "1" and S[right + 1] == "0":
            remain -= 1
        right += 1
    ans = max(ans, right - left)
    if left == right:
        right += 1
    else:
        if S[left] == "0" and S[left + 1] == "1":
            remain += 1
    left += 1
print(ans)
