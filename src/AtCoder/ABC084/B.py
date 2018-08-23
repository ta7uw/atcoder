A, B = map(int, input().split())
S = input()
import re
print("Yes" if re.match("^[0-9]{%d}-[0-9]{%d}$" %(A, B), S) else "No")
