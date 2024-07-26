import sys

def is_palindrome(str):
    if str == str[::-1]:
        return True
    else:
        return False
    
n = int(sys.stdin.readline().strip())

for i in range(n):
    print(f'Test case #{i+1}:')
    p = int(sys.stdin.readline().strip())
    switch_list = []
    for _ in range(p):
        src, dest = map(str, sys.stdin.readline().split())
        switch_list.append([src, dest])
    
    t = int(sys.stdin.readline().strip())
    for _ in range(t):
        string = sys.stdin.readline().strip()
        original = string

        for s in switch_list:
            if s[0] in string:
                string = string.replace(s[0], s[1])

        if (is_palindrome(string)):
            print(original, 'YES')
        else:
            print(original, 'NO')
    print()