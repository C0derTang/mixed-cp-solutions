import sys

sys.stdin = open('paintbarn.in', 'r')
sys.stdout = open('paintbarn.out', 'w')

input = sys.stdin.readline

n, k = map(int, input().split())

dp = [[0]*1001 for _ in range(1001)]
for _ in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    dp[x1][y1] += 1
    dp[x1][y2] -= 1
    dp[x2][y1] -= 1
    dp[x2][y2] += 1

ans = 0
for i in range(1001):
    for j in range(1001):
        if i > 0:
            dp[i][j] += dp[i-1][j]
        if j > 0:
            dp[i][j] += dp[i][j-1]
        if i > 0 and j > 0:
            dp[i][j] -= dp[i-1][j-1]
        if dp[i][j] == k:
            ans += 1

print(ans)