import sys

input = sys.stdin.readline

n = int(input())

class Node:
	def __init__(self):
		self.parent = None
		self.r = 0
		self.children = []

nodes = [Node() for _ in range(n)]
for i in range(n):
	p, c = map(int, input().split())
	if p == -1:
		continue
	nodes[i].parent = nodes[p-1]
	nodes[i].r = c
	nodes[p-1].children.append(nodes[i])

ans = []
for i in range(n):
	if nodes[i].r == 1:
		disrespect = True
		for child in nodes[i].children:
			if child.r == 0:
				disrespect = False
				break
		if disrespect:
			for child in nodes[i].children:
				child.parent = nodes[i].parent
			nodes[i] = None
			ans.append(i+1)
if ans:
	print(*ans)
else:
	print(-1)