import sys

sys.stdin = open('moocast.in', 'r')
sys.stdout = open('moocast.out', 'w')

input = sys.stdin.readline

n = int(input())

x, y, p, = [0]*n, [0]*n, [0]*n
for i in range(n):
	x[i], y[i], p[i] = map(int, input().split())

neighbors = [[] for _ in range(n)]
for a in range(n):
	for b in range(a+1, n):
		distsq = (x[a]-x[b])**2 + (y[a]-y[b])**2
		if distsq <= p[a]**2:
			neighbors[a].append(b)
		if distsq <= p[b]**2:
			neighbors[b].append(a)

ans = 0
for i in range(n):
	visited = set()
	stack = [i]
	while stack:
		cur = stack.pop()
		visited.add(cur)
		for x in neighbors[cur]:
			if x in visited:
				continue
			stack.append(x)
	ans = max(ans, len(visited))
print(ans)
