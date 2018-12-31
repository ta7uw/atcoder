q = int(input())
lr = []
for i in range(q):
    lr.append(list(map(int, input().split())))


def binarySearch(alist, item):
    first = 0
    last = len(alist) - 1
    found = False
    while first <= last and not found:
        midpoint = (first + last) // 2
        if alist[midpoint] == item:
            found = True
        else:
            if item < alist[midpoint]:
                last = midpoint - 1
            else:
                first = midpoint + 1
    return found


def is_prime(num):
    i = 2
    while i ** 2 <= num:
        if num % i == 0:
            return False
        i += 1
    return True


primes = []
for i in range(2, 10 ** 5 + 1):
    if is_prime(i):
        primes.append(i)

like_2017 = []
for i in range(len(primes)):
    if binarySearch(primes, primes[i] * 2 - 1):
        like_2017.append(2 * primes[i] - 1)

count = [0 for _ in range(10 ** 5)]
for like in like_2017:
    count[like] += 1
for i in range(len(count) - 1):
    count[i + 1] += count[i]
for i in range(q):
    print(count[lr[i][1]] - count[lr[i][0] - 1])
