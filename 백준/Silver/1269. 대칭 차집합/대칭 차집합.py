import sys
A, B = map(int, sys.stdin.readline().split())

set_A = list(map(int, sys.stdin.readline().split()))
set_A = set(set_A)

set_B = list(map(int, sys.stdin.readline().split()))
set_B = set(set_B)

diff_A_to_B = set.difference(set_A, set_B)
diff_B_to_A = set.difference(set_B, set_A)

print(len(diff_A_to_B) + len(diff_B_to_A))