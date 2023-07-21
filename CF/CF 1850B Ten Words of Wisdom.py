import sys

input = sys.stdin.readline

def solve():
	n = int(input())
	maxval = 0
	ans = 0
	for i in range(n):
		a, b = map(int, input().split())
		if a <= 10:
			if b > maxval:
				maxval = b
				ans = i+1
	print(ans)

for _ in range(int(input())):
	solve()