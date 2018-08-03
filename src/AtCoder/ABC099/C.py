n = int(input())
num = float("inf")
for i in range(n + 1):
    rec = 0
    k = i
    while k > 0:
        rec += k % 6
        k = k // 6
    k = n - i
    while k > 0:
        rec += k % 9
        k = k // 9
    num = min(num, rec)
 
print(num)
