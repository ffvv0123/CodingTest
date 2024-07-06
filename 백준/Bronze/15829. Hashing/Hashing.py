L = int(input())
string = input()

hash_sum = 0

for i in range(len(string)):
    char = ord(string[i]) - ord('a') + 1
    hash_sum += char * 31 ** i

print(hash_sum % 1234567891)