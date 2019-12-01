S = input()
s_length = len(S)
ans = s_length
for i in range(s_length - 1):
    if not S[i] == S[i + 1]:
        ans = min(ans, max(i + 1, s_length - i - 1))
print(ans)