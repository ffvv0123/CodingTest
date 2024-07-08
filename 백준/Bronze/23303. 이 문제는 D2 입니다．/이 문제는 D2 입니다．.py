string = input()
answer = 'unrated'

for i in range(len(string) - 1):
    if (string[i] == 'D' or string[i] == 'd') and string[i+1] == '2':
        answer = 'D2'
        break

print(answer)