import sys

input = sys.stdin.readline

def can_reach(segs, k):
	lpos = rpos = 0
	for i in range(len(segs)):
		rpos = min(rpos + k, segs[i][1])
		lpos = max(lpos - k, segs[i][0])
		if lpos > rpos:
			return False
	return True

def solve():
	n = int(input())
	segs = [[int(i) for i in input().split()] for _ in range(n)]
	
	left = 0
	right = 1000000000
	while left <= right:
		mid = (left+right)//2
		if can_reach(segs, mid):
			right = mid-1
		else:
			left = mid+1
	print(left)

for _ in range(int(input())):
	solve()
