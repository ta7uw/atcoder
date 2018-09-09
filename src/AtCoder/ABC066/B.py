S = input()


def check_even(stri):
    if len(stri) % 2 !=0:
        return False
    else:
        half = int(len(stri)/2)
        if stri[:half] == stri[half:]:
            return True
        else:
            return False


for i in range(len(S)):
    if check_even(S[:-(i+1)]):
        print(len(S)-(i+1))
        exit()

