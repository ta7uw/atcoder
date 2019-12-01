S = input()
T = input()
S_dic = {}
T_dic = {}

for i in range(len(S)):
    s = S[i]
    t = T[i]
    if s in S_dic:
        S_dic[s] += 1
    else:
        S_dic[s] = 1

    if t in T_dic:
        T_dic[t] +=1

    else:
        T_dic[t] = 1

S_dic = sorted(S_dic.items(), key= lambda x:x[1])
T_dic = sorted(T_dic.items(), key=lambda x:x[1])
f = True
if len(S_dic) >= len(T_dic):
    length = len(T_dic)
else:
    length = len(S_dic)
for i in range(length):
    s = S_dic[i][1]
    t = T_dic[i][1]
    if s != t:
        f = False

if f:
    print("Yes")
else:
    print("No")
S = input()
T = input()
S_dic = {}
T_dic = {}

for i in range(len(S)):
    s = S[i]
    t = T[i]
    if s in S_dic:
        S_dic[s] += 1
    else:
        S_dic[s] = 1

    if t in T_dic:
        T_dic[t] +=1

    else:
        T_dic[t] = 1

S_dic = sorted(S_dic.items(), key= lambda x:x[1])
T_dic = sorted(T_dic.items(), key=lambda x:x[1])
f = True
if len(S_dic) >= len(T_dic):
    length = len(T_dic)
else:
    length = len(S_dic)
for i in range(length):
    s = S_dic[i][1]
    t = T_dic[i][1]
    if s != t:
        f = False

if f:
    print("Yes")
else:
    print("No")
