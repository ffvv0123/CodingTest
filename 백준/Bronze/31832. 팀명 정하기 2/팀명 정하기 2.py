import sys

def check_upper_lower(id):
    upper_num, lower_num = 0, 0

    for s in id:
        if 'A' <= s <= 'Z':
            upper_num += 1
        elif 'a' <= s <= 'z':
            lower_num += 1
    
    if upper_num > lower_num:
        return False
    else:
        return True

def check_length(id):
    if len(id) > 10:
        return False
    else:
        return True

def check_in_alphabet(id):
    for s in id:
        if s < '0' or s > '9':
            return True
    return False
            

N = int(input())

for i in range(N):
    id = sys.stdin.readline().strip()

    if check_upper_lower(id) and check_length(id) and check_in_alphabet(id):
        print(id)
        break