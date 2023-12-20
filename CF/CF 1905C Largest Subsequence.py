import sys

input = sys.stdin.readline

def solve():
	n = int(input())
	s = list(input().strip())

	ans = 0
	cur = [s[0]]
	ind = [0]
	for i in range(1, n):
		while cur and s[i] > cur[-1]:
			cur.pop()
			ind.pop()
		cur.append(s[i])
		ind.append(i)
	
	sub = 0
	while sub+1 < len(cur) and cur[sub+1] == cur[0]:
		sub += 1
		
	for i in range(len(cur)):
		if i < len(cur)-i:
			s[ind[i]], s[ind[len(cur)-i-1]] = cur[len(cur)-i-1], cur[i]

	for i in range(n-1):
		if s[i] > s[i+1]:
			print(-1)
			return
	print(len(cur)-sub-1)

for _ in range(int(input())):
	solve()