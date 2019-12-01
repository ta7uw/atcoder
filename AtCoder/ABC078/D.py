N, Z, W = map(int, input().split())
a_list = [i for i in map(int, input().split())]

if N == 1:
    print(abs(W-a_list[0]))
    exit()
    
max_a = max(a_list)
print(max(abs(a_list[-1]-W), abs(a_list[-2]-a_list[-1])))
    
