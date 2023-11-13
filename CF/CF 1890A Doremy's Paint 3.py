import sys, collections

input = sys.stdin.readline

def solve():
	n = int(input())
	a = [int(i) for i in input().split()]

	count = collections.Counter(a)
	if len(count) == 1:
		print('Yes')
	elif len(count) == 2:
		if abs(count[max(count, key=count.get)] - count[min(count, key=count.get)]) > 1:
			print('No')
		else:
			print('Yes')
	elif len(count) > 2:
		print('No')
	
	

for _ in range(int(input())):
	solve()