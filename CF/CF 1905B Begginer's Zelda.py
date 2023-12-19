import sys

input = sys.stdin.readline

def solve():
	n = int(input())
	adj = [[] for _ in range(n)]
	for _ in range(n-1):
		a, b = map(int, input().split())
		adj[a-1].append(b-1)
		adj[b-1].append(a-1)
	leaves = 0
	for a in adj:
		if len(a) == 1:
			leaves += 1
	ans = leaves // 2
	if leaves % 2 == 1:
		ans += 1
	print(ans)

for _ in range(int(input())):
	solve()