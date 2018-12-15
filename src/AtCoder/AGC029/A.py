S = input()
S_list = []
for i in S:
    S_list.append(i)

w_count = S.count("W")
b_count = S.count("B")
c = 0

for i in range(len(S)):

    if S[i] == "B":
        c += w_count
    else:
        w_count -= 1

print(c)
