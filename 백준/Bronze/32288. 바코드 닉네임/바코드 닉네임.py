n = int(input())
string = input()
answer = ""

for i in range(n):
    if string[i] == 'l':
        answer += 'L'
    else:
        answer += 'i'

print(answer)