S = input()
T = input()
S_dic = [0 for _ in range(26)]
T_dic = [0 for _ in range(26)]

alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
            "l", "m", "n","o", "p", "q", "r", "s", "t", "u", "v", 
            "w", "x", "y", "z"]

for i in range(len(S)):
    s = S[i]
    t = T[i]
    si = alphabet.index(s)
    ti = alphabet.index(t)

    if S_dic[si] == 0:
        S_dic[si] = ti
    elif S_dic[si] != ti:
        print("No")
        exit()

    if T_dic[ti] == 0:
        T_dic[ti] = si
    elif T_dic[ti] != si:
        print("No")
        exit()

print("Yes")

