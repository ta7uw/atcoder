A, B, C = map(int, input().split())

sum_num = A + B + C

before_A = A
before_B = B
before_C = C
count = 1

if before_A % 2 == 1 or before_B % 2 == 1 or before_C % 2 == 1:
    print(0)
    exit()

while True:
    after_A = (sum_num - before_A) // 2
    after_B = (sum_num - before_B) // 2
    after_C = (sum_num - before_C) // 2
    if after_A == before_A and after_B == before_B and after_C == before_C:
        print(-1)
        exit()

    if after_A % 2 == 0 and after_B % 2 == 0 and after_C % 2 == 0:
        count += 1
        before_A = after_A
        before_B = after_B
        before_C = after_C

    else:
        print(count)
        exit()
