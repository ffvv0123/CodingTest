import sys

n = int(input())

oldest_live_day = 1990 * 365
oldest_name = ''

youngest_live_day = 2010 * 365 + 12 * 31
youngest_name = ''

for _ in range(n):
    name, date, month, year = sys.stdin.readline().split()
    current_live_day = int(year) * 365 + int(month) * 31 + int(date)
    
    if current_live_day < youngest_live_day:
        youngest_name = name
        youngest_live_day = current_live_day
    if current_live_day > oldest_live_day:
        oldest_name = name
        oldest_live_day = current_live_day

print(oldest_name)
print(youngest_name)
