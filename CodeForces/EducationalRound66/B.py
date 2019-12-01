L = int(input())
items = []
ans = 0
over = 2 ** 32 - 1

import sys

end = []

for i in range(L):
    tmp = tuple(sys.stdin.readline().split())
    items.append(tmp)

for_sum = 1
for_stack = []
start = False


def mu(ite, ans):
    tmp = 1
    for it in ite:
        tmp *= it
        if tmp + ans > over:
            print("OVERFLOW!!!")
            exit()
    return tmp


for i, tmp in enumerate(items):
    if tmp[0] == "add":
        if not start:
            ans += 1
        else:
            ans += mu(for_stack, ans)
    elif tmp[0] == "for":
        start = True
        s = int(tmp[1])
        for_sum *= s
        for_stack.append(s)
    else:
        for_stack.pop()
        if len(for_stack) == 0:
            start = False
    if ans > over:
        print("OVERFLOW!!!")
        exit()
if ans > over:
    print("OVERFLOW!!!")
else:
    print(ans)
