import sys

input = sys.stdin.readline

def solve():
	a,b,c = map(int, input().split())
	if a+b >= 10 or b+c >= 10 or c+a >= 10:
		print('yes')
	else:
		print('no')

for _ in range(int(input())):
	solve()