def combination(n, r):
    r = min(n - r, r)
    result = 1
    for i in range(n, n - r, -1):
        result *= i
    for i in range(1, r + 1):
        result //= i
    return result


N, A, B = map(int, input().split())
v_list = list(map(int, input().split()))
v_list.sort(reverse=True)

mean_max = sum(v_list[:A]) / A
comb = 0
if v_list[0] != v_list[A - 1]:
    x = v_list.count(v_list[A - 1])
    y = v_list[:A].count(v_list[A - 1])
    comb = combination(x, y)
else:
    x = v_list.count(v_list[A - 1])
    for i in range(A, B + 1):
        if v_list[i - 1] == v_list[0]:
            comb += combination(x, i)

print("{:.10f}".format(mean_max))
print(comb)
