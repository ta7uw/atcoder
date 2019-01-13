S = input()

ans = False

if S[:7] == "keyence":
    ans = True

if S.find("k") != -1:
    if S.find("keyenc") == 0 and S[-1] == "e":
        ans = True
    if S.find("keyen") == 0 and S[-2:] == "ce":
        ans = True
    if S.find("keye") == 0 and S[-3:] == "nce":
        ans = True
    if S.find("key") == 0 and S[-4:] == "ence":
        ans = True
    if S.find("ke") == 0 and S[-5:] == "yence":
        ans = True
    if S.find("k") == 0 and S[-6:] == "eyence":
        ans = True
    if S[-7:] == "keyence":
        ans = True
if ans:
    print("YES")
else:
    print("NO")
