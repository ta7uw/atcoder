N = int(input())
s1 = input()
s2 = input()
mod = 10 ** 9 + 7

i = 0
prev = -1
ans = 1
while i < N:
    if s1[i] == s2[i]:
        if prev == 1:
            ans *= 1
        elif prev == 0:
            ans *= 2
        else:
            ans *= 3
        prev = 0
    else:
        if prev == 0:
            ans *= 2
        elif prev == 1:
            ans *= 3
        else:
            ans *= 6
        i += 1
        prev = 1
    i += 1

print(ans % mod)
