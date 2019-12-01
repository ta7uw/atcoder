N = int(input())
T, A = map(int, input().split())
h_list = list(map(int, input().split()))
 
T_list = []
margin = []
for i in range(N):
    h = h_list[i]
    t = T - h*0.006
    margin.append(abs(A-t))
 
min_margin = float("inf")
min_i = -1
 
for i in range(N):
    if min_margin >= margin[i]:
        min_margin = margin[i]
        min_i = i+1
print(min_i)
