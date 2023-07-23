import sys

input = sys.stdin.readline

def solve():
	n = int(input())
	a = [int(i) for i in input().split()]

	min_gap = float('inf')
	for i in range(n-1):
		min_gap = min(min_gap, a[i+1] - a[i])
	
	if min_gap < 0:
		print(0)
		return
	print(min_gap//2+1)

for _ in range(int(input())):
	solve()