import sys, math, collections

input = sys.stdin.readline

def solve():
	n = int(input())
	a = sum([int(i) for i in input().split()])
	if math.sqrt(a).is_integer():
		print('YES')
	else:
		print('NO')

for _ in range(int(input())):
	solve()