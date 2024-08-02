def parser(data):
    mole_dict = {'C':0, 'H':0, 'O':0}

    last_mole = ''
    for s in data:
        if s == 'C':
            last_mole = 'C'
            mole_dict['C'] += 1
        elif s == 'H':
            last_mole = 'H'
            mole_dict['H'] += 1
        elif s == 'O':
            last_mole = 'O'
            mole_dict['O'] += 1
        else:
            mole_dict[last_mole] -= 1
            mole_dict[last_mole] += int(s)
    
    return mole_dict['C'], mole_dict['H'], mole_dict['O']
        



equation = input()

M1, M2 = equation.split('+')
M2, M3 = M2.split('=')

M1_C, M1_H, M1_O = parser(M1)
M2_C, M2_H, M2_O = parser(M2)
M3_C, M3_H, M3_O = parser(M3)

for m1 in range(1, 11):
    for m2 in range(1, 11):
        for m3 in range(1, 11):
            if (m1 * M1_C + m2 * M2_C == m3 * M3_C):
                if (m1 * M1_H + m2 * M2_H == m3 * M3_H):
                    if (m1 * M1_O + m2 * M2_O == m3 * M3_O):
                        print(m1, m2, m3)
                        exit()