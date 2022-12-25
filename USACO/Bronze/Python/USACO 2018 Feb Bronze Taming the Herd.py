import sys

sys.stdin = open('taming.in', 'r')
sys.stdout = open('taming.out', 'w')

input = sys.stdin.readline

n = int(input())
days = [int(i) for i in input().split()]
days[0] = 0

val = True
for i in range(n-1, 0, -1):
    if days[i] > 0:
        if days[i-1] != days[i]-1 and days[i-1] != -1:
            val = False
            break
        else:
            days[i-1] = days[i] - 1

if val:
    print(days.count(0), days.count(0) + days.count(-1))
else:
    print(-1)