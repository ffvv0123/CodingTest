import sys
N = int(sys.stdin.readline().strip())
my_cards = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline().strip())
finder = list(map(int, sys.stdin.readline().split()))

card_set = dict()
for card in my_cards:
    if card not in card_set:
        card_set[card] = 1
    else:
        card_set[card] += 1

for i in finder:
    if i in card_set:
        print(card_set[i], end = " ")
    else:
        print(0, end = " ")