import sys, collections, math

input = sys.stdin.readline

def solve():
	n = int(input())
	a = [int(i) for i in input().split()]

	ans = 0
	last = a[-1]
	for i in range(n-2, -1, -1):
		if a[i] > a[i+1]:
			ans += math.ceil(a[i]/a[i+1])-1
			a[i] //= math.ceil(a[i]/a[i+1])
	print(ans)


for _ in range(int(input())):
	solve()