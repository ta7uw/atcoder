import datetime

S = input()

he = datetime.datetime(2019, 4, 30)
ta = datetime.datetime.strptime(S, '%Y/%m/%d')

if he < ta:
    print("TBD")
else:
    print("Heisei")
