import sys, math, collections

input = sys.stdin.readline

def solve():
	a, b, c = map(int, input().split())
	if a != b and b == c:
		print(a)
	elif a != b and a == c:
		print(b)
	else:
		print(c)

for _ in range(int(input())):
	solve()