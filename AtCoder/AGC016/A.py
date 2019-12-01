N = input()

from collections import Counter

counter = Counter(N)
answer = float("inf")

for c in counter:

    margin = 0
    items = list(N.split(c))
    margin = 0
    for item in items:
        margin = max(margin, len(item))

    answer = min(answer, margin)
print(answer)
