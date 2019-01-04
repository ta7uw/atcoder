N = int(input())
S = input()

s_list = [0 for _ in range(N)]
answer = S
stack = []
for i in range(N):
    if len(stack) == 0 and S[i] == ")":
        answer = "(" + answer
    elif len(stack) != 0 and S[i] == ")":
        stack.pop()
    else:
        stack.append(S[i])

print(answer + len(stack) * ")")
