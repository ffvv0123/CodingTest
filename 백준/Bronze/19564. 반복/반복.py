S = input()
answer = 1

muse = S[0]

for i in range(1, len(S)):
    if ord(S[i]) <= ord(muse):
        answer += 1
    muse = S[i]

print(answer)