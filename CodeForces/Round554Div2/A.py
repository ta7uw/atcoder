N, M = map(int, input().split())
a_list = list(map(int, input().split()))
b_list = list(map(int, input().split()))

a_odd = [a for a in a_list if a % 2 == 1]
a_even = [a for a in a_list if a % 2 == 0]
b_odd = [b for b in b_list if b % 2 == 1]
b_even = [b for b in b_list if b % 2 == 0]

print(min(len(a_odd), len(b_even)) + min(len(a_even), len(b_odd)))
