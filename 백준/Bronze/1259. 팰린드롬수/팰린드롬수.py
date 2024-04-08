while True:
    num = input()
    if num == '0':
        break
    if num == num[::-1]: #이 부분은 입력받은 수를 뒤집어 앞의 숫자와 비교해주는 슬라이스 함수에 대해 몰랐지만 검색하여 활용하게 되었습니다
        print("yes")
    else:
        print("no")