import sys

input = sys.stdin.readline

def solve():
	n, m = map(int, input().split())
	print(max(n, m))

for _ in range(int(input())):
	solve()