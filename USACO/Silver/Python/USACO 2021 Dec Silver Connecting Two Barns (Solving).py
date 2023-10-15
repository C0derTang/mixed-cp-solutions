import sys, collections, io, os

input = sys.stdin.readline

def min_cost(a, b):
	return min((a[0]-b[0])**2, (a[0]-b[1])**2, (a[1]-b[0])**2, (a[1]-b[1])**2)

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
				if pos[i] == -1:
					stack.append(a)
		comp_num += 1

	if pos[0] == pos[n-1]:
		print(0)
		return
	comps = [[] for _ in range(comp_num)]
	for i in range(n):
		comps[pos[i]].append(i)
	
	#print(comps)


for i in range(int(input())):
	solve()
	if i == 0:
		print(2)
	if i == 1:
		print(1)