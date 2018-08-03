n = int(input())
s = input()
E = s.count("E")
W = 0
min_num = n
for s_i in s:
    if s_i == "E":
        E -= 1
    else :
        W += 1

    change_man = E + W - bool(s_i == "W")
    min_num = min(min_num, change_man)
print(min_num)
