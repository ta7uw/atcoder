N, M = map(int, input().split())
S = input()
T = input()
def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def lcm(a, b):
    return a * b // gcd(b, a % b)


L = lcm(N, M)

f = False

s_step = L // N
t_step = L // M
sL = lcm(s_step, t_step)
s = 0
t = 0

for i in range(0, L, sL):
    if i == 0:
        if S[i] == T[i]:
            continue
        else:
            f = True
            break
    else:
        s = i // s_step
        t = i // t_step
        if s > N - 1:
            break
        if t > M - 1:
            break
        if S[s] == T[t]:
            continue
        else:
            f = True
            break

if f:
    print(-1)
else:
    print(L)


