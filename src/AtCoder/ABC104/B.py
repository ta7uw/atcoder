S = input()

if S[0] == "A":
    count = S[2:-1].count("C")
    if count == 1:
        S = S.replace("A", "").replace("C", "")
        if S.islower():

            print("AC")
        else:
            print("WA")
    else:
        print("WA")
else:
    print("WA")
