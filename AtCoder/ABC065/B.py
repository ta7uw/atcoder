N = int(input())
a_list = []
for i in range(N):
    a_list.append(int(input()))

checked = set()
if a_list[0] == 2:
    print(1)
    exit()

checked.add(a_list[0])
count = 1
btn = a_list[0]
for i in  range(1, N):
    ai = a_list[btn-1]
    count +=1
    if ai in checked:
        print(-1)
        exit()
    else:
        if ai == 2:
            print(count)
            exit()
        else:
            checked.add(ai)
            btn = ai
print(-1)
