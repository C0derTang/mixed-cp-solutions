import sys

input = sys.stdin.readline

def calcscore(h, t):
	
	solved = penalty = tot = 0
	for q in t:
		if tot+q > h:
			break
		solved += 1
		tot += q
		penalty += tot
		
	return solved, penalty
	
def solve():
	n, m, h = map(int, input().split())
	r = calcscore(h, sorted([int(i) for i in input().split()]))
	ans = 1
	for _ in range(n-1):
		t = calcscore(h, sorted([int(i) for i in input().split()]))
		if t[0] > r[0]:
			ans += 1
		elif t[0] == r[0]:
			if t[1] < r[1]:
				ans += 1
	print(ans)
	
for _ in range(int(input())):
	solve()