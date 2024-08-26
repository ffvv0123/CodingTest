import sys

T = int(sys.stdin.readline().strip())
for _ in range(T):
    S = sys.stdin.readline().strip()
    reversed_S = S[::-1]
    cnt = 0

    if S == S[::-1]:
        print(1, len(S) // 2 + 1)
    else:
        l = 0
        r = len(S) - 1

        while l <= r:
            if S[l] == S[r]:
                cnt += 1
                l += 1
                r -= 1
            else:
                break
        print(0, cnt + 1)

    