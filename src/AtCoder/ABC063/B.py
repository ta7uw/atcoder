S=input()
s_set = set()
for s in S:
    s_set.add(s)
    
print("yes" if len(s_set) == len(S) else "no")
