A, B, C, D, E, F = map(int, input().split())

max_water = 0
max_sugar = 0
max_con = 0
max_AB = 31
max_CD = 101

for a in range(max_AB):
    for b in range(max_AB):
        water = (100 * A) * a + (100 * B) * b
        if water == 0:
            break

        for c in range(max_CD):
            for d in range(max_CD):
                sugar = C * c + D * d
                if water + sugar > F:
                    break

                con = 100*sugar / (water + sugar)
                if water/100 * E >= sugar and con >= max_con:
                    max_con = con
                    max_water = water
                    max_sugar = sugar
print(str(max_water+max_sugar) + " " + str(max_sugar))

