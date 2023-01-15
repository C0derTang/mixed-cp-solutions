"""
ID: tanchr1
LANG: PYTHON3
TASK: beads
"""

import sys

sys.stdin = open('beads.in', 'r')
sys.stdout = open('beads.out', 'w')

input = sys.stdin.readline

n = int(input())
beads = input().strip()

def calc(s):
	l = 0
	ret = 0
	cur = s[0]
	switch = False
	for r in range(n):
		if s[r] == 'w':
			pass
		elif cur != s[r]:
			if cur == 'w':
				cur = s[r]
			elif not switch:
				cur = s[r]
				switch = True
			else:
				ret = max(ret, r-l)
				while s[l] != cur:
					l += 1
				while l > 0 and s[l-1] == 'w':
					l -= 1
				cur = s[r]
	ret = max(ret, r-l+1)
	return ret
		

ans = 0
for br in range(n):
	test = beads[br:] + beads[:br]
	ans = max(ans, calc(test))
print(ans)