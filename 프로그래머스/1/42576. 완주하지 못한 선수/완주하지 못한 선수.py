'''
dictionary 연습문제
참가자의 해시값을 모두 더해놓고
완주자의 해시값을 다 빼
남은 해시값으로 역추적
'''

def solution(participant, completion):
    answer = ''
    
    hashDict = {}
    hashSum = 0
    
    for p in participant:
        hashDict[hash(p)] = p
        hashSum += hash(p)
    
    for c in completion:
        hashSum -= hash(c)
    
    return hashDict[hashSum]