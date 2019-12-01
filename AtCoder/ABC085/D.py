N, H = map(int, input().split())
a_list = []
b_list = []
for i in range(N):
    a, b = map(int, input().split())
    a_list.append(a)
    b_list.append(b)
count = 0
a = max(a_list)
b_list.sort()
while len(b_list) >= 1 and H >= 1:
    if b_list[-1] >= a:
        b = b_list.pop(-1)
        H -= b
        count += 1
    else:
        break
if H <= 0:
    print(count)
else:
    tmp = H // a if H % a == 0 else H //a + 1
    print(count + tmp)
