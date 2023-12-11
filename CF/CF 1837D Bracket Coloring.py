import sys

input = sys.stdin.readline

def solve():
	n = int(input())
	s = input().strip()

	if n % 2 != 0 or s.count('(') != s.count(')'):
		print(-1)
		return
	
	fwd_no = set()
	stack = []
	for i, c in enumerate(s):
		if c == '(':
			stack.append((i,c))
		else:
			if stack:
				stack.pop()
			else:
				fwd_no.add(i)
	for i, c in stack:
		fwd_no.add(i)
	
	rvs_no = set()
	stack = []
	for i in range(n-1, -1, -1):
		if s[i] == '(':
			stack.append((i,s[i]))
		else:
			if stack:
				stack.pop()
			else:
				rvs_no.add(i)
	for i, c in stack:
		rvs_no.add(i)

	if not fwd_no or not rvs_no:
		print(1)
		print(*[1]*n)
	else:
		ans = [0]*n
		for i in range(n):
			if i in fwd_no:
				ans[i] = 1
			else:
				ans[i] = 2
		print(2)
		print(*ans)


for _ in range(int(input())):
	solve()