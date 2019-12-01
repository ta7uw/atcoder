import numpy as np

x1, y1, x2, y2 = map(int, input().split())


def get_rotation_matrix(rad):
    rot = np.array([[np.cos(rad), -np.sin(rad)],
                    [np.sin(rad), np.cos(rad)]], dtype=np.int32)
    return rot


X1 = x1 - x2
Y1 = y1 - y2
r = get_rotation_matrix(np.pi / 2)
rotated = np.dot(-r, np.asarray([X1, Y1], dtype=np.int32))
print(str(rotated[0] + x2) + " " + str(rotated[1] + y2), end=" ")

X2 = -rotated[0]
Y2 = -rotated[1]
r = get_rotation_matrix(np.pi / 2)
XY4 = np.dot(-r, np.asarray([X2, Y2],dtype=np.int32))
x4 = XY4[0]
y4 = XY4[1]
print(str(x4 + rotated[0] + x2) + " " + str(y4 + rotated[1] + y2), end="")
