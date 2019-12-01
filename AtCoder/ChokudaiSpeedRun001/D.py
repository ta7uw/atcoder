N = int(input())
a_list = list(map(int, input().split()))

a_list.sort()
for a in a_list:
    print(a)
