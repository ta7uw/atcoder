X, A, B = map(int, input().split())



if A - B >= 0:
    print("delicious")

else:
    if B - A < X +1:
        print("safe")
    else:
        print("dangerous")
