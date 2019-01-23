s = input()
x, y = map(int, input().split())
command = s.split("T")

command_length = len(command)

x_command = []
y_command = []
for i in range(command_length):
    c = len(command[i])
    if i % 2 == 0:
        x_command.append(c)

    else:
        y_command.append(c)
x -= x_command.pop(0)
x_command.sort(reverse=True)
y_command.sort(reverse=True)

c_x = 0
c_y = 0
for c in x_command:
    if x - c_x >= 0:
        c_x += c
    else:
        c_x -= c

for c in y_command:
    if y - c_y > 0:
        c_y += c
    else:
        c_y -= c
if c_x == x and c_y == y:
    print("Yes")
else:
    print("No")
