n = int(input())
log = set()

for i in range(n):
    name, condition = input().split(' ')
    
    if condition == 'enter':
        log.add(name)
    elif condition == 'leave':
        log.remove(name)

log = sorted(list(log), reverse= True)

for i in log:
    print(i)