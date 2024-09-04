S = input().strip()

checker = S[0]
cnt = 0

for i in range(1, len(S)):
    if S[i] != checker:
        checker = S[i]
        cnt += 1

if cnt % 2 == 0:
    print(cnt // 2)
else:
    print(cnt//2 + 1)