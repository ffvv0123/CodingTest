'''
M미터 필요함
절단기 -> H
20 15 10 17
-> 15를 H로 잡으면 15 15 10 15를 자르고
-> 5 2를 들고감
-> M미터만 들고가기 위해서 설정할 수 있는 최대 높이는?

윗부분만 잘라설 갈거임
-> H를 0부터 최댓값까지 두고 절반씩 잘라가면서 답 찾아가기

'''
import sys
N, M = map(int, sys.stdin.readline().split())
height = list(map(int, sys.stdin.readline().split()))

low = 1
high = sum(height)

while(low <= high):
    mid = (low + high) // 2
    cnt = 0

    for tree in height:
        if tree > mid:
            cnt += tree - mid
    
    if cnt >= M:
        low = mid + 1
    else:
        high = mid - 1
    
print(high)