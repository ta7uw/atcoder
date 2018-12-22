n = int(input())
a_list = [int(input()) for _ in range(n)]

print('second' if all(a_list[i] % 2 == 0 for i in range(n)) else 'first')