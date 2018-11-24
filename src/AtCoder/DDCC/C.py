n = int(input())
mod = 1000000007

r = 0
for i in range(1, n+1):
    q_max = n // i
    p_max = i ** 10 - (i-1) ** 10
    q_max = q_max ** 10 
    r += p_max * q_max

print(int(r % mod))

