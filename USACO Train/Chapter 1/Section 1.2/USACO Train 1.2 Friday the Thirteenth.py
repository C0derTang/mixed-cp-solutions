"""
ID: tanchr1
LANG: PYTHON3
TASK: friday
"""

import sys

sys.stdin = open('friday.in', 'r')
sys.stdout = open('friday.out', 'w')

input = sys.stdin.readline

n = int(input())
ans = [0] * 7

day = 0
for y in range(1900, 1900+n):
    for m in range(1,13):
        leap = False
        if y % 100 == 0:
            if y % 400 == 0:
                leap = True
        elif y % 4 == 0:
            leap = True
        
        if m == 2:
            days = 28 + leap
        elif m == 4 or m == 6 or m == 9 or m == 11:
            days = 30
        else:
            days = 31
        for d in range(1, days+1):
            if d == 13:
                ans[day%7] += 1
            day += 1
print(*(ans[5:] + ans[:5]))