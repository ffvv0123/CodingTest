'''
조합 풀이, 해시 풀이, 집합 풀이
'''

## 조합 풀이 -> 시간초과
# import itertools as iter
# def solution(nums):
#     answer = 0
#     combination = list(set(iter.combinations(nums, len(nums)//2)))
    
#     for i in combination:
#         if answer == len(nums)//2:
#             return answer
#         answer = max(answer, len(set(i)))
#     return answer

# 집합 풀이

def solution(nums):
    answer = 0
    
    length = len(nums)
    nums = set(nums)
    
    if len(nums) >= length//2:
        answer = length//2
    else:
        answer = len(nums)
        
    return answer
    