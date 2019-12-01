N = int(input())
S = input()
output = 0
for i in range(N):
    output = max(output, len(set(S[:i]) & set(S[i:])))
print(output)
