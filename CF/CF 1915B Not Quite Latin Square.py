import sys, math, collections

input = sys.stdin.readline

def solve():
	check = {'A':0, 'B':0, 'C':0}
	for _ in range(3):
		row = input().strip()
		for i in row:
			if i in check:
				check[i] += 1
	for k, v in check.items():
		if v == 2:
			print(k)
			return

for _ in range(int(input())):
	solve()