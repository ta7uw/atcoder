D, G = map(int, input().split())

p_list = []
c_list = []
pm = {}
cm = {}
for i in range(D):
    p, c = map(int, input().split())
    p_list.append(p)
    c_list.append(c)
    pm[i] = p
    pm[i] = c

p_sort = sorted(pm.items())
print(p_sort)
fi = 0
co = 0
result1=0
for i in range(D-1, -1, -1):
    if fi >= G:
        break
    p = p_list[i]
    while p > 0:
        p -= 1
        fi += 100 * (i+1)
        result1 +=1
        if p==0:
            fi += c_list[i]
        if fi >= G:
            break
x = 0
result2 = 0
for k, p in p_sort.items():
    x = 100*(k+1)*p + cm[k]
    resutl2 += p
    if x >= G:
        break
    
    
print(min([result1, result2])





