S = input()

while True:
    if S == '':
        print('YES')
        break

    if S[:2] == 'pi':
        S = S[2:]
    elif S[:2] == 'ka':
        S = S[2:]
    elif S[:3] == 'chu':
        S = S[3:]
    else:
        print('NO')
        break
    