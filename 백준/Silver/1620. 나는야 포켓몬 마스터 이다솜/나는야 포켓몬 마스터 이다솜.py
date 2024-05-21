import sys
N, M = map(int, sys.stdin.readline().split())

pokemons = dict()
reverse_pokemons = dict()
for i in range(1, N+1):
    pokemon = sys.stdin.readline().strip()
    pokemons[i] = pokemon
    reverse_pokemons[pokemon] = i

for i in range(M):
    command = sys.stdin.readline().strip()
    if ord('A') <= ord(command[0]) <= ord('Z'):
        print(reverse_pokemons[command])
    else:
        print(pokemons[int(command)])