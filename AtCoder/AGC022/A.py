S = input()

if len(S) == 26:
    tmp = S[:-1]
    f = True
    removed = [S[-1]]
    while len(tmp) > 0:
        removed.sort()
        for r in removed:
            if tmp[-1] < r:
                print(tmp[:-1] + r)
                exit()
        removed.append(tmp[-1])
        tmp = tmp[:-1]


alphabet = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k",
            "l", "m", "n", "o", "p", "q", "r", "s", "t", "u",
            "v", "w", "x", "y", "z"]
words = set(alphabet)
input_words = set()

for s in S:
    input_words.add(s)

margin_word = words - input_words
margin_word = list(margin_word)
margin_word.sort()

if len(margin_word) == 0:
    print(-1)
else:
    print(S + margin_word[0])
