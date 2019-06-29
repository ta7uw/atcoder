S = input()
if len(set(list(S))) == 2:
    tmp = list(set(list(S)))
    if S.count(tmp[0]) == 2 and S.count(tmp[1]) == 2:
        print("Yes")
    else:
        print("No")

else:
    print("No")
