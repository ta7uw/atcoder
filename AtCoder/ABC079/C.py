x = input()
A = int(x[0])
B = int(x[1])
C = int(x[2])
D = int(x[3])
 
def cal(a, b, opx):
    if opx == "+":
        return a + b
    else:
        return a - b
 
op = ["+", "-"]
result = ""
for op1 in op:
    for op2 in op:
        for op3 in op:
            if cal(cal(cal(A, B, op1),C,  op2), D, op3) == 7:
                print(str(A) + op1 + str(B) + op2 + str(C) + op3 + str(D) + "=7")
                exit()
                
