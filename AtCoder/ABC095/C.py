A, B, C, X, Y = map(int, input().split())
price = 0
min_num = min([X,Y])
if A/2 + B/2 > C:
    X -= min_num
    Y -= min_num
    if X == 0:
        print(min([min_num *2* C + B * Y, (Y+min_num)*2*C]))
    else:
        print(min([min_num *2* C + A * X, (X+min_num)*2*C]))
else:
    print(A*X+ B*Y)
