import sys, collections, io, os

input = sys.stdin.readline

def solve():
	n, m = map(int, input().split())
	adj = [[] for _ in range(n)]
	for _ in range(m):
		i, j = map(int, input().split())
		i -= 1
		j -= 1
		adj[i].append(j)
		adj[j].append(i)
	
	pos = [-1]*n
	comp_num = 0
	for i in range(n):
		if pos[i] != -1:
			continue
		stack = [i]
		while stack:
			cur = stack.pop()
			pos[cur] = comp_num
			for a in adj[cur]:
				if pos[a] == -1:
					stack.append(a)
		comp_num += 1

	if pos[0] == pos[n-1]:
		print(0)
		return
	comps = [[] for _ in range(comp_num)]
	for i in range(n):
		comps[pos[i]].append(i)
	#print(comps)

	dist1 = [float('inf')]*len(comps)
	dist2 = [float('inf')]*len(comps)

	barn1 = comps[pos[0]]
	barn2 = comps[pos[n-1]]
	p1 = 0
	for i in range(n):
		d = abs(barn1[p1]-i)
		while p1 < len(barn1)-1 and abs(barn1[p1+1]-i) < d:
			p1 += 1
		dist1[pos[i]] = min(d, dist1[pos[i]])
	
	p2 = 0
	for i in range(n):
		d = abs(barn2[p2]-i)
		while p2 < len(barn2)-1 and abs(barn2[p2+1]-i) < d:
			p2 += 1
		dist2[pos[i]] = min(d, dist2[pos[i]])

	ans = float('inf')
	for i in range(len(comps)):
		ans = min(ans, dist1[i]**2+dist2[i]**2)
	print(ans)


for i in range(int(input())):
	solve()
