'''
N개 스트링
-> 접두사 X 집합의 부분집합의 최대 크기
-> set으로 중복제거부터 하고, 딕셔너리도 가능 -> 굳이 안해도 되긴 함
테스트 케이스가 작아 -> N^2 가능
'''

N = int(input())
prefix = []
answer = 0

for i in range(N):
    tmp = input()
    prefix.append(tmp)

prefix = sorted(prefix, key = lambda x: len(x))

for i in range(N):
    flag = False
    for j in range(i+1,N):
        if prefix[i] in prefix[j][0:len(prefix[i])]:
            flag = True
            break

    if not flag:
        answer += 1

print(answer)
    
