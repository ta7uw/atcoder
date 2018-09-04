S = input()
T = input()

start = -1
for i in range(len(S)-len(T)+1):
    match = True
    for j in range(len(T)):
        if not (S[i+j] == T[j] or S[i+j] == "?"):
            match = False
    if match:
        start = i


if start == -1:
    print('UNRESTORABLE')
else:
    result = S[:start] + T + S[start+len(T):]
    print(result.replace("?", "a"))

