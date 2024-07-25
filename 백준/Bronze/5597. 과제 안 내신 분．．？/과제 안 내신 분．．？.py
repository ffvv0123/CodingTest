hw = set()
total = set([i+1 for i in range(30)])
for i in range(28):
    hw.add(int(input()))

diff = total - hw
diff = list(diff)
diff.sort()

print(diff[0])
print(diff[-1])