import sys, collections

input = sys.stdin.readline

def solve():
	n, m = map(int, input().split())
	s = input().strip()
	t = input().strip()

	sval = True
	for i in range(n-1):
		if s[i] == s[i+1]:
			sval = False
			break
	
	if sval:
		print('Yes')
		return
	
	tval = True
	for i in range(m-1):
		if t[i] == t[i+1]:
			tval = False
			break
	
	if not sval and not tval or t[0] != t[-1]:
		print('No')
		return
	
	good = True
	for i in range(n-1):
		if s[i+1] == s[i]:
			if s[i] != t[0]:
				continue
			else:
				good = False
				break
	if good:
		print('Yes')
	else:
		print('No')

for _ in range(int(input())):
	solve()