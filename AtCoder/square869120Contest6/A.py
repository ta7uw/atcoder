N, T = map(int, input().split())
a_list = list(map(int, input().split()))
ans = (sum(a_list) + T - 1) // T
print(ans)
