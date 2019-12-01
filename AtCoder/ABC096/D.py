n = int(input())


def is_prime(num):
    i = 2
    while i ** 2 <= num:
        if num % i == 0:
            return False
        i += 1
    return True


candi = []
for i in range(2, 55556):
    if is_prime(i) and i % 5 == 1:
        candi.append(i)

print(*candi[:n])
