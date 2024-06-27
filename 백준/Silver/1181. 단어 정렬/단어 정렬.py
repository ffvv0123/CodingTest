N = int(input())
str_list = []

for _ in range(N):
    tmp = input()
    str_list.append(tmp)

str_list = list(set(str_list))

str_list.sort()
str_list.sort(key = lambda x: len(x))

for str in str_list:
    print(str)