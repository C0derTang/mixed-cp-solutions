import sys

input = sys.stdin.readline

n = int(input())
grid = [[None]*(n+1) for _ in range(n+1)]

for i in range(n):
    directions, cost = map(str, input().split())
    grid[i][:n] = [c for c in directions]
    grid[i][n] = int(cost)
grid[n] = [int(i) for i in input().split()]

dp = [[0]*(n+1) for _ in range(n+1)]

def calc():
    ret = 0
    for i in range(n):
        ret += dp[i][n] * grid[i][n] + dp[n][i] * grid[n][i]
    return ret

def update(i, j, v):
    while True:
        dp[i][j] += v
        if i == n or j == n:
            return
        if grid[i][j] == 'R':
            j += 1
        else:
            i += 1

for i in range(n+1):
    for j in range(n+1):
        if i != n and j != n:
            dp[i][j] = 1
        if i != 0 and j != n and grid[i-1][j] == 'D':
            dp[i][j] += dp[i-1][j]
        if i != n and j != 0 and grid[i][j-1] == 'R':
            dp[i][j] += dp[i][j-1]

print(calc())

q = int(input())
for _ in range(q):
    i, j = map(int, input().split())
    i -= 1
    j -= 1
    cur = dp[i][j]
    update(i, j, -cur)
    if grid[i][j] == 'R':
        grid[i][j] = 'D'
    else:
        grid[i][j] = 'R'
    update(i, j, cur)
    print(calc())