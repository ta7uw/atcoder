n = int(input())
a_list = list(map(int, input().split()))
for i in range(n):
    while a_list[i] % 2 == 0:
        a_list[i] //= 2
print(len(set(a_list)))