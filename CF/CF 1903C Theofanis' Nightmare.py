import sys, collections

input = sys.stdin.readline

def solve():
	n = int(input())
	a = [int(i) for i in input().split()]

	suff = [0]*(n+1)
	for i in range(n-1, -1, -1):
		suff[i] = suff[i+1] + a[i]
	#print(suff)

	ans = 0
	group = 1
	for i in range(n):
		if i != 0 and suff[i] > 0:
			group += 1
		ans += group*a[i]
		
	print(ans)

for _ in range(int(input())):
	solve()