N, T = map(int, input().split())
route = {}
 
for i in range(N):
    c, t = map(int, input().split())
    route[c] = t
 
 
val = float("inf")
for c, t in route.items():
    if t <= T:
        if c <= val:
            val = c
 
if val < float("inf"):
    print(val)
else:
    print("TLE")
