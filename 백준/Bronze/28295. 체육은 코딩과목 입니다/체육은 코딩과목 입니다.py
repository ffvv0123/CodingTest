direction = ['N', 'E', 'S', 'W']
command = 0

for i in range(10):
    command += int(input())

print(direction[command % 4])