import sys, collections

input = sys.stdin.readline

def solve():
	n = int(input())
	s = input().strip()[::-1]
	ans = 0
	
	l = r = -1
	for i in range(n):
		if ans != -1:
			if r < i and s[i] == '0':
				r += 1
			else:
				while r < n-1 and s[r+1] == '1':
					r += 1
				if r == n-1:
					ans = -1
				else:
					ans += r-l
				r += 1
			l += 1
		
			
		sys.stdout.write(str(ans) + ' ')
	sys.stdout.write('\n')
			


for _ in range(int(input())):
	solve()