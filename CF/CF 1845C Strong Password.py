import sys, io, os, collections

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
	s = [int(i) for i in input().strip()]
	n = len(s)
	m = int(input())
	l = input().strip()
	r = input().strip()
	mx = 0
	for i in range(m):
		li = int(l[i])
		ri = int(r[i])
		nmx = mx
		for c in range(li, ri+1):
			cur = mx
			while cur < n and s[cur] != c:
				cur += 1
			nmx = max(nmx, cur)
		mx = nmx+1
	print('YES' if mx > n else 'NO')

for _ in range(int(input())):
	solve()