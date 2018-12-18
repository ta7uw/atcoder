N = int(input())


def brute_force(s, remain):
    if remain == 0:
        print(s)
    else:
        brute_force(s + "a", remain - 1)
        brute_force(s + "b", remain - 1)
        brute_force(s + "c", remain - 1)


brute_force("", N)
