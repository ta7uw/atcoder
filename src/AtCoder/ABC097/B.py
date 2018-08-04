X = int(input())
max_num = 1
for i in range(1, 32):
    for j in range(2, 10):
        q = i ** j
        if q <= X and max_num <= q:
            max_num = q
print(max_num)
