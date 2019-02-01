S = input()
N = len(S)

dp = [[[-1 for _ in range(N)] for _ in range(N)] for _ in range(N)]


def rec(i, j, k):
    """
    :param i: index
    :param j: 最後に変更したindex
    :param k: "("が")"よりどれだけ多いか
    :return:
    """
    if k < 0 or (i == N and k != 0):
        return float("inf")
    if i == N and k == 0:
        return j

    if dp[i][j][k] != -1:
        return dp[i][j][k]

    if S[i] == "(":
        ans1 = rec(i + 1, i, k - 1) + 1
        ans2 = rec(i + 1, j, k + 1)
    else:
        ans1 = rec(i + 1, i, k + 1) + 1
        ans2 = rec(i + 1, j, k - 1)
    ans = min(ans1, ans2)
    dp[i][j][k] = ans
    return ans


print(rec(0, 0, 0))
