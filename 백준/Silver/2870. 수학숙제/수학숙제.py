import sys

N = int(sys.stdin.readline().strip())
ans = []

for _ in range(N):
    input_data = sys.stdin.readline().strip()
    length = len(input_data)

    tmp = ""
    for i in range(length):
        if input_data[i] >= 'a' and input_data[i] <= 'z':
            if tmp != "":
                ans.append(int(tmp))
                tmp = ""
            continue
        else:
            tmp += input_data[i]
    
    if tmp != "":
        ans.append(int(tmp))

ans.sort()
for i in ans:
    print(i)
