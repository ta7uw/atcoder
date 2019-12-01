N = int(input())
t_list = list(map(int, input().split()))
a_list = list(map(int, input().split()))

t_max = -1
t_i = 0
a_max = -1
a_i = 0
ans = 1
mod = 10 ** 9 + 7

for i in range(N):
    t = t_list[i]
    a = a_list[i]
    if t > t_max:
        t_max = t
        t_i = i
    if a >= a_max:
        a_max = a
        a_i = i
if a_max == t_max and t_i <= a_i:
    prev_a = a_list[-1]
    prev_t = t_list[0]
    for i in range(1, t_i):
        t = t_list[i]
        if t == prev_t:
            ans *= prev_t
            ans %= mod
        prev_t = t
    for i in range(N-2, t_i, -1):
        a = a_list[i]
        if a == prev_a:
            ans *= prev_a
            ans %= mod
        prev_a = a
    print(ans % mod)
else:
    print(0)
