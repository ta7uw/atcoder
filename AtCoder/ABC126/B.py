S = input()

if S[0:2] > "12":
    if "01" <= S[2:4] <= "12":
        print("YYMM")
    else:
        print("NA")

elif "01" <= S[0:2] <= "12":
    if "01" <= S[2:4] <= "12":
        print("AMBIGUOUS")
    else:
        print("MMYY")
elif S[0:2] == "00":
    if "01" <= S[2:4] <= "12":
        print("YYMM")
    else:
        print("NA")

else:
    print("NA")
