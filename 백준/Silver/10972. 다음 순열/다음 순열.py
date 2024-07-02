# import sys

# N = int(input())
# current_permutaiton = list(map(int, sys.stdin.readline().split()))

# is_last = True
# answer = []

# for i in range(N-1, 0, -1):
#     if current_permutaiton[i-1] < current_permutaiton[i]:
#         is_last = False
#         tmp_index = i-1

#         for j in range(N-1, 0, -1):
#             if current_permutaiton[tmp_index] < current_permutaiton[j]:
#                 current_permutaiton[tmp_index], current_permutaiton[j] = current_permutaiton[j], current_permutaiton[tmp_index]

#                 answer = current_permutaiton[:i] + sorted(current_permutaiton[i:])
#                 break
#         break

# if is_last:
#     print(-1)
# else:
#     print(' '.join(map(str, answer)))
    

# '''
# 1 4 3 2

# 1. 뒤에서부터 체크, 뒷값이 앞값보다 큰거 찾기
# (1 4) 3 2

# 2. 뒤에서부터 비교, 체크의 앞 값보다 큰 값이 있다면 교체
# (2 4) 3 1

# 3. 교체한 값 뒤부터 정렬

# 2 1 3 4

# 얼핏 코드만 보면 복잡도가 되게 커보인다. 하지만, 조건문에 들어가게 되면 이전의 반복을 실행하지 않게 되므로 실제 복잡도는 크지 않다.
# 이게 가능할까 했지만 생각보다 계산량이 많지 않다는 것을 알 수 있었다.
# -> O(NlogN)으로 통과함. 그런데 아래 풀이가 더 좋다.
# '''

## O(N) 풀이도 있다. 가장 최적화된 풀이가 이거임.
def next_permutation(current_permutation):
    N = len(current_permutation)
    
    # Step 1: Find the first element that is smaller than its next element (from right to left)
    for i in range(N-1, 0, -1):
        if current_permutation[i-1] < current_permutation[i]:
            break
    else:
        # If no such element is found, the current permutation is the last permutation
        return -1
    
    # Step 2: Find the smallest element on the right side of the found element that is larger than it
    for j in range(N-1, i-1, -1):
        if current_permutation[i-1] < current_permutation[j]:
            # Step 3: Swap these two elements
            current_permutation[i-1], current_permutation[j] = current_permutation[j], current_permutation[i-1]
            break
    
    # Step 4: Reverse the sequence from the element right after the found element to the end
    current_permutation[i:] = reversed(current_permutation[i:])
    
    return current_permutation

# Example usage:
N = int(input())
current_permutation = list(map(int, input().split()))
result = next_permutation(current_permutation)
if result == -1:
    print(-1)
else:
    print(' '.join(map(str, result)))
