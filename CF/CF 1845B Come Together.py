import sys, io, os, collections

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
	ax, ay = map(int, input().split())
	bx, by = map(int, input().split())
	cx, cy = map(int, input().split())

	d1x, d1y = bx-ax, by-ay
	d2x, d2y = cx-ax, cy-ay
	#print(d1x, d1y, d2x, d2y)

	ans = 1
	if (d1x > 0 and d2x > 0) or (d1x*-1 > 0 and d2x*-1 > 0):
		ans += min(abs(d1x), abs(d2x))
	if (d1y > 0 and d2y > 0) or (d1y*-1 > 0 and d2y*-1 > 0):
		ans += min(abs(d1y), abs(d2y))
	print(ans)

for _ in range(int(input())):
	solve()