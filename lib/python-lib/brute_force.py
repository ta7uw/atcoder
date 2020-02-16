def brute_force(s, remain):
    if remain == 0:
        print(s)
    else:
        brute_force(s + "a", remain - 1)
        brute_force(s + "b", remain - 1)
        brute_force(s + "c", remain - 1)


brute_force("", 3)

# aaa
# aab
# aac
# aba
# abb
# abc
# aca
# acb
# acc
# baa
# bab
# bac
# bba
# bbb
# bbc
# bca
# bcb
# bcc
# caa
# cab
# cac
# cba
# cbb
# cbc
# cca
# ccb
# ccc