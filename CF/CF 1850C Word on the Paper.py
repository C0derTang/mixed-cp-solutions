import sys

input = sys.stdin.readline

def solve():
	grid = [input().strip() for _ in range(8)]
	ans = ''
	for i in range(8):
		for j in range(8):
			if grid[i][j] != '.':
				ans += grid[i][j]
				cur = i+1
				while cur < 8 and grid[cur][j] != '.':
					ans += grid[cur][j]
					cur += 1
				print(ans)
				return

for _ in range(int(input())):
	solve()