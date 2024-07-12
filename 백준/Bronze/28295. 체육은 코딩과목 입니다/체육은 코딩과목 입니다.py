direction = ['N', 'E', 'S', 'W']
current_pos = 'N'

for i in range(10):
    command = int(input())
    if command == 1:
        current_pos = direction[(direction.index(current_pos) + 1) % 4]
    elif command == 2:
        current_pos = direction[(direction.index(current_pos) + 2) % 4]
    elif command == 3:
        current_pos = direction[(direction.index(current_pos) + 3) % 4]

print(current_pos)