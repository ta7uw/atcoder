s = input()
S = list(s)
S = list(reversed(S))

for i in range(len(s) - 1):
    if S[i] == "A" and S[i + 1] == "W":
        S[i] = "C"
        S[i + 1] = "A"

S = reversed(S)
print("".join(S))
