string = input()
str_list = []

for i in range(len(string)):
    str_list.append(string[i:])

str_list = sorted(str_list, key = lambda x: x)
for s in str_list:
    print(s)