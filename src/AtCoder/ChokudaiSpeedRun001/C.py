N = int(input())
a_list = list(map(int, input().split()))

for a in a_list[:-1]:
    print(a, end=",")
print(a_list[-1])
