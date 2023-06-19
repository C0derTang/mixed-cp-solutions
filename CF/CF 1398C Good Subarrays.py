import sys

input = sys.stdin.readline

def solve():
	n = int(input())
	a = [int(i) for i in input().strip()]

	pref = [0]*(n+1)
	for i in range(n):
		pref[i+1] = pref[i] + a[i]

	comp = {}
	for i in range(n+1):
		if pref[i] - i not in comp:
			comp[pref[i]-i] = 0
		comp[pref[i] - i] += 1

	ans = 0
	for v in comp.values():
		ans += v*(v-1)//2
	print(ans)

for _ in range(int(input())):
	solve()