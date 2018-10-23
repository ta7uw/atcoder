N, A, B = map(int, input().split())

judge = False

turn = 0
while not judge:
    if turn == 0:
        if A - B == 1:
            print("Borys")
            exit()
        else:
            A += 1
            turn = 1
    else:
        if A - B == 1:
            print("Alice")
            exit()
        else:
            B -= 1
            turn = 0


