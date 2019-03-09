H, W = map(int, input().split())
h, w = map(int, input().split())

print(H * W - W * h - w * (H - h))
