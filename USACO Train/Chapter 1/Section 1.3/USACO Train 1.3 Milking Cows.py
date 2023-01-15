"""
ID: tanchr1
LANG: PYTHON3
TASK: milk2
"""

import sys

sys.stdin = open('milk2.in', 'r')
sys.stdout = open('milk2.out', 'w')

input = sys.stdin.readline

n = int(input())
intervals = [[int(i) for i in input().split()] for _ in range(n)]
intervals.sort(key=lambda x: x[1])

for i in range(n-1, 0, -1):
    i1 = intervals[i]
    i2 = intervals[i-1]
    if i1[0] <= i2[1]:
        intervals[i-1] = [min(i1[0], i2[0]), max(i1[1], i2[1])]
        intervals.pop(i)

max_milk = max_idle = 0
for i in intervals:
    max_milk = max(max_milk, i[1] - i[0])

for i in range(len(intervals)-1):
    max_idle = max(max_idle, intervals[i+1][0] - intervals[i][1])

print(max_milk, max_idle)
