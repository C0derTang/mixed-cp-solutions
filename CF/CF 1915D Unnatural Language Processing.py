import sys, math, collections

input = sys.stdin.readline

def solve():
	n = int(input())
	a = [int(i) for i in input().split()]
	pd = [0]
	for i, v in enumerate(a):
		if i%2 == 0:
			pd.append(pd[-1]+v)
		else:
			pd.append(pd[-1]-v)

	first = {}
	check = False
	for i, d in enumerate(pd):
		if d in first:
			check = True
			break
		first[d] = i
	if check:
		print('YES')
	else:
		print('NO')
	

for _ in range(int(input())):
	solve()
