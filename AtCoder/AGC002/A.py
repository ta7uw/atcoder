a, b = map(int, input().split())

if a > 0 and b > 0:
    print("Positive")

elif (a >= 0 and b <= 0) or (a <= 0 and b >= 0):
    print("Zero")

else:
    abs_ab = abs(a-b)
    
    if abs_ab % 2 == 0:
        print("Negative")
    else:
        print("Positive")
