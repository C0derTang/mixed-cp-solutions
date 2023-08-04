import sys

input = sys.stdin.readline

def solve():
	n = int(input())
	a = [int(i) for i in input().split()]
	cur = a[0]
	ans = 1
	for i in range(n):
		cur &= a[i]
		if cur == 0:
			if i == n-1:
				break
			ans += 1
			cur = a[i+1]
	if cur != 0:
		ans -= 1
	print(max(1, ans))


for _ in range(int(input())):
	solve()