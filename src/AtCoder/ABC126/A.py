N, K = map(int, input().split())
S = input()

T = ""
for i in range(N):
    if i == K - 1:
        T += S[i].lower()
    else:
        T += S[i]
print(T)
