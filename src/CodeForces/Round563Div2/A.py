N = int(input())
a_list = list(map(int, input().split()))

a_set = set(a_list)

if len(a_set) == 1:
    print(-1)
    exit()

a_list.sort()
for a in a_list:
    print(a, end=" ")
print()
