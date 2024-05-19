# [Silver I] Z - 1074 

[문제 링크](https://www.acmicpc.net/problem/1074) 

### 성능 요약

메모리: 31120 KB, 시간: 48 ms

### 분류

분할 정복, 재귀

### 제출 일자

2024년 5월 19일 23:02:18

### 문제 설명

<p>한수는 크기가 2<sup>N</sup> × 2<sup>N</sup>인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.</p>

<p style="text-align:center"><img alt="" src="https://u.acmicpc.net/21c73b56-5a91-43aa-b71f-9b74925c0adc/Screen%20Shot%202020-12-02%20at%208.09.46%20AM.png" style="width: 100px; height: 99px;"></p>

<p>N > 1인 경우, 배열을 크기가 2<sup>N-1</sup> × 2<sup>N-1</sup>로 4등분 한 후에 재귀적으로 순서대로 방문한다.</p>

<p>다음 예는 2<sup>2</sup> × 2<sup>2</sup> 크기의 배열을 방문한 순서이다.</p>

<p style="text-align:center"><img alt="" src="https://u.acmicpc.net/adc7cfae-e84d-4d5c-af8e-ee011f8fff8f/Screen%20Shot%202020-12-02%20at%208.11.17%20AM.png" style="width: 250px; height: 252px;"></p>

<p>N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.</p>

<p>다음은 N=3일 때의 예이다.</p>

<p style="text-align:center"><img alt="" src="https://u.acmicpc.net/d3e84bb7-9424-4764-ad3a-811e7fcbd53f/Screen%20Shot%202020-12-30%20at%2010.50.47%20PM.png" style="width: 533px; height: 535px;"></p>

### 입력 

 <p>첫째 줄에 정수 N, r, c가 주어진다.</p>

### 출력 

 <p>r행 c열을 몇 번째로 방문했는지 출력한다.</p>

```
'''
N = 1

01
23 -> 이 순서대로 방문함.

N = 2 -> 0에서 Z돌리고 1에서 Z돌리고, ... 재귀다 재귀 -> 반복도 된다잉
count = 0해놓고 방문하면 1씩 올려
-> if 답 걸리면 리턴뱉기
-> 아니면 2차원 배열 만들고 해보기
N = 15
-> 2^30 -> 0.5초면 충분
-> 메모리 터짐

'''

## 메모리 터지는 풀이
## 4번의 재귀를 모두 부를 필요도 없다. r,c범위로 조건 맞는거만 재귀 돌리면 시간도 개선 가능함
# import sys
# N, r, c = map(int, sys.stdin.readline().split())
# count = 0

# maps = [[0] * 2**N for _ in range(2**N)]

# def Z(N, x, y):
#     global count

#     if N == 1:
#         maps[x][y] = count
#         maps[x][y+1] = count + 1
#         maps[x+1][y] = count + 2
#         maps[x+1][y+1] = count + 3
#         count += 4
#     else:
#         Z(N-1, x, y)
#         Z(N-1, x, y + 2**(N-1))
#         Z(N-1, x + 2**(N-1), y)
#         Z(N-1, x + 2**(N-1), y + 2**(N-1))

# Z(N, 0, 0)
# print(maps[r][c])

## 공간을 없애고 재귀로 바로 해결 -> 시간초과 ㅋㅋ
## -> 4번의 재귀를 굳이 해야하는가? ㄴㄴ
# import sys
# N, r, c = map(int, sys.stdin.readline().split())
# count = 0

# def Z(N, x, y):
#     global count

#     if N == 1:
#         if x == r and y == c:
#             print(count)
#             return True
#         elif x == r and y + 1 == c:
#             print(count+1)
#             return True
#         elif x + 1 == r and y == c:
#             print(count+2)
#             return True
#         elif x + 1 == r and y + 1 == c:
#             print(count+3)
#             return True
#         count += 4        
#     else:
#         Z(N-1, x, y)
#         Z(N-1, x, y + 2**(N-1))
#         Z(N-1, x + 2**(N-1), y)
#         Z(N-1, x + 2**(N-1), y + 2**(N-1))

# Z(N, 0, 0)

## 시간, 공간 모두 개선
```

