def divisors(num):
    """
    約数全列挙
    """
    divisors = []
    for i in range(1, int(num ** 0.5) + 1):
        if num % i == 0:
            divisors.append(i)
            if i != num // i:
                divisors.append(num // i)

    return divisors


T = int(input())
for t in range(T):
    N = int(input())
    d_list = list(map(int, input().split()))
    d_list.sort()
    target = min(d_list) * max(d_list)
    res = divisors(target)
    res.remove(1)
    res.remove(target)
    res.sort()
    if len(d_list) == len(res):
        flg = True
        for i in range(len(res)):
            if d_list[i] == res[i]:
                continue
            else:
                print(-1)
                flg = False
                break
        if flg:
            print(target)
    else:
        print(-1)
