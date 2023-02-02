class Cow:
    def __init__(self, arr, time):
        self.start = arr
        self.end = arr+time

import sys

sys.stdin = open('cowqueue.in', 'r')
sys.stdout = open('cowqueue.out', 'w')

input = sys.stdin.readline

n = int(input())
cows = [None] * n
for i in range(n):
    arr, time = map(int, input().split())
    cows[i] = Cow(arr, time)
cows.sort(key=lambda i:i.start)

time = 0
for cow in cows:
    if cow.start < time:
        cow.end += time-cow.start
        cow.start = time

    time = cow.end

print(time)