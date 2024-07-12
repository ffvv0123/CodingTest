import sys

tile = []
answer = 0

N, M, K = map(int ,sys.stdin.readline().split())
for i in range(N):
    tile.append(list(sys.stdin.readline().rstrip()))

step = N * M // K**2

for x in range(K):
    for y in range(K):
        count_list = [0] * 26

        for i in range(0, N - K + 1, K):
            for j in range(0, M - K + 1, K):
                tmp_tile = tile[i+x][j+y]
                count_list[ord(tmp_tile) - ord('A')] += 1
        
        num_of_max_tile = max(count_list)
        answer += step - num_of_max_tile
        max_tile = chr(count_list.index(num_of_max_tile) + ord('A'))

        for i in range(0, N - K + 1, K):
            for j in range(0, M - K + 1, K):
                tile[i+x][j+y] = max_tile

print(answer)
for line in tile:
    print("".join(line))