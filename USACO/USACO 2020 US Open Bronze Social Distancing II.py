import sys

sys.stdin = open('socdist2.in', 'r')
sys.stdout = open('socdist2.out', 'w')

input = sys.stdin.readline

n = int(input())
cows = [[int(i) for i in input().split()] for _ in range(n)]
cows.sort()
#print(cows)

max_r = n-1
for i, cow in enumerate(cows):
    if not cow[1]:
        if i > 0 and cows[i-1][1]:
            max_r =  min(max_r, cow[0]-cows[i-1][0]-1)
        if i < n-1 and cows[i+1][1]:
             max_r =  min(max_r, cows[i+1][0]-cow[0]-1)
#print(max_r)

ans = 1
cur = cows[0]
for i in range(n):
    if not cows[i][1]:
        continue
    if cows[i][0] > cur[0] + max_r:
        ans += 1
    cur = cows[i]
print(ans)