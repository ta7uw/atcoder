N = input()

if len(N) == N.count("9"):
    print(9*len(N))
    exit()

if len(N) -1 == N.count("9"):
    if N[0] == str(9):
        print(9 * (len(N)-1) + 8)
        exit()
        
    sd = 0
    N = int(N)
    while N > 0:
        sd += N % 10
        N //= 10
    print(sd)
    exit()

if N[0] == 1:
    print(9 * (len(N) - 1) + 8)
else:
    print(int(N[0])-1 + 9 * (len(N) - 1))

