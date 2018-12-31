n = int(input())
s = input()

S1 = "SS"
S2 = "WW"
S3 = "SW"
S4 = "WS"
S_list = [S1, S2, S3, S4]
for S in S_list:
    last = ""
    for i in range(n):
        if i == 0:
            if S[0] == "S":
                if s[i] == "o":
                    last = S[1]
                else:
                    last = "S" if S[1] == "W" else "W"
            else:
                if s[i] == "o":
                    last = "S" if S[1] == "W" else "W"
                else:
                    last = "S" if S[1] == "S" else "W"

        elif 1 <= i < n - 1:
            if S[i] == "S":
                if s[i] == "o":
                    S += S[i-1]
                else:
                    S += "W" if S[i-1] == "S" else "S"
            else:
                if s[i] == "o":
                    S += "S" if S[i-1] == "W" else "W"
                else:
                    S += "S" if S[i-1] == "S" else "W"
        elif i == n - 1:
            if S[i] == "S":
                if s[i] == "o" and S[0] == S[i - 1] and S[i] == last:
                    print(S)
                    exit()
                if s[i] == "x" and S[0] != S[i - 1] and S[i] == last:
                    print(S)
                    exit()
            else:
                if s[i] == "o" and S[0] != S[i - 1] and S[i] == last:
                    print(S)
                    exit()
                if s[i] == "x" and S[0] == S[i - 1] and S[i] == last:
                    print(S)
                    exit()

print(-1)