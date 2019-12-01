A, B, K = map(int, input().split())


def g(num):
    ans = []
    for i in range(1, num + 1):
        if num % i == 0:
            ans.append(i)
    return ans


a = g(A)
b = g(B)

r = list(set(a) & set(b))
r.sort(reverse=True)

print(list(r)[K - 1])
