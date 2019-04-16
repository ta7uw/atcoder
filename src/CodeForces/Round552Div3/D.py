n, b, a = map(int, input().split())
s_list = list(map(int, input().split()))

ans = 0
now_a = a
now_b = b
for i, s in enumerate(s_list):
    if s == 0:
        if now_a > 0:
            now_a -= 1
        else:
            if now_b > 0:
                now_b -= 1
            else:
                print(i)
                exit()

    if s == 1:
        if now_a < a:
            if now_b > 0:
                now_b -= 1
                now_a += 1
            else:
                if now_a > 0:
                    now_a -= 1
                else:
                    print(i)
                    exit()
        else:
            now_a -= 1

print(n)
