N = int(input())
s_list =  "".join(input().split())

s_list = s_list.replace("G", "").replace("P", "").replace("W", "")
if len(s_list) == 0 :
    print("Three")
else:
    print("Four")


