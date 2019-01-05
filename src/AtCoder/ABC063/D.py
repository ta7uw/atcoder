N, A, B = map(int, input().split())
h_list = [int(input()) for _ in range(N)]
h_list.sort(reverse=True)
h_max = h_list[0]


def add_attack(t):
    attack = B * t
    for i in range(N):
        h = h_list[i]
        h -= attack
        if h > 0:
            t -= (h + (A - B) - 1) // (A - B)
            if t < 0:
                return False
    return True


t_min = 1
t_max = (h_max + B - 1) // B

while t_min < t_max - 1:
    t_mid = (t_min + t_max) // 2
    if add_attack(t_mid):
        t_max = t_mid
    else:
        t_min = t_mid
print(t_max)
