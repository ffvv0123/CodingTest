N = int(input())
S = input()

if N <= 25:
    print(S)
else:
    tmp = S[11:N-11]

    if (tmp[-1] == '.' and tmp.count('.') == 1) or tmp.count('.') == 0:
        print(S[:11] + '...' + S[N-11:])
    else:
        print(S[:9] + '......' + S[N-10:])