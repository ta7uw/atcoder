n, k = map(int, input().split())
s = input()
s_list = list(s)
s_list.sort()
result = ""
count = 0
for i in range(n):
    for j, si in enumerate(s_list):
        if s[i] == si:
            result += si
            s_list.remove(si)
            break
        else:
            if i == n-1:
                break
            pre = s_list[:j]
            suf = s_list[j+1:]
            pre.extend(suf)
            n_m = []
            remain = list(s[i+1:])
            for m in range(len(pre)):
                if pre[m] in remain:
                    remain.remove(pre[m])
                    continue
                else:
                    n_m.append(pre[m])
            if len(n_m) + 1 + count <= k:
                count += 1
                result += si
                s_list.remove(si)
                break

if len(s_list) > 0:
    print(result + s_list[0])
else:
    print(result)