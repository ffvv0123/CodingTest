def cntSelf(num):
    cnt = 99

    for i in range(100, int(num) + 1):
        if int(str(i)[1]) * 2 == int(str(i)[0]) + int(str(i)[2]):
            cnt += 1

    return cnt

N = input()

if(int(N) < 100):
    print(N)
elif(int(N) >= 100):
    print(cntSelf(N))