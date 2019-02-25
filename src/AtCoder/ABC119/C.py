N, A, B, C = map(int, input().split())
l_list = [int(input()) for _ in range(N)]

inf = float("inf")


def dfs(cur, a, b, c):
    if cur == N:
        return abs(a - A) + abs(b - B) + abs(c - C) - 30 if min(a, b, c) > 0 else inf
    ans0 = dfs(cur + 1, a, b, c)
    ans1 = dfs(cur + 1, a + l_list[cur], b, c) + 10
    ans2 = dfs(cur + 1, a, b + l_list[cur], c) + 10
    ans3 = dfs(cur + 1, a, b, c + l_list[cur]) + 10
    return min(ans0, ans1, ans2, ans3)


print(dfs(0, 0, 0, 0))
