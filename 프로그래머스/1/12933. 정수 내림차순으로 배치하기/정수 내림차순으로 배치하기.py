def solution(n):
    
    answer, tmp = sorted(str(n), reverse = True), ''

#     for i in answer:
#         tmp += i
    
#     answer = int(tmp)
    
    return int("".join(answer))