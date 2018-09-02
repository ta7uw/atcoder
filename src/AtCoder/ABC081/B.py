N = int(input())
a_list = list(map(int, input().split()))
count = 0
while True:
    tmp = []
    for a in a_list:
        if a % 2 == 0:
            a = a / 2
            tmp.append(a)
        else:
            print(count)
            exit()
    count += 1
    a_list = tmp
