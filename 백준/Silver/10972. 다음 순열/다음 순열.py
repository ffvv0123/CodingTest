import sys

N = int(input())
current_permutaiton = list(map(int, sys.stdin.readline().split()))

is_last = True
answer = []

for i in range(N-1, 0, -1):
    if current_permutaiton[i-1] < current_permutaiton[i]:
        is_last = False
        tmp_index = i-1

        for j in range(N-1, 0, -1):
            if current_permutaiton[tmp_index] < current_permutaiton[j]:
                current_permutaiton[tmp_index], current_permutaiton[j] = current_permutaiton[j], current_permutaiton[tmp_index]

                answer = current_permutaiton[:i] + sorted(current_permutaiton[i:])
                break
        break

if is_last:
    print(-1)
else:
    print(' '.join(map(str, answer)))
    

'''
1 4 3 2

1. 뒤에서부터 체크, 뒷값이 앞값보다 큰거 찾기
(1 4) 3 2

2. 뒤에서부터 비교, 체크의 앞 값보다 큰 값이 있다면 교체
(2 4) 3 1

3. 교체한 값 뒤부터 정렬

2 1 3 4
'''
