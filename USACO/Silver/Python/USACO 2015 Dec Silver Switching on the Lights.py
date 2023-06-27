import sys, collections

sys.stdin = open('lightson.in', 'r')
sys.stdout = open('lightson.out', 'w')

input = sys.stdin.readline

n, m = map(int, input().split())
lights = {}
for _ in range(m):
	x, y, a, b = map(int, input().split())
	if (x-1, y-1) not in lights:
		lights[(x-1, y-1)] = []
	lights[(x-1, y-1)].append((a-1, b-1))
#print(lights)

on = [[False]*n for _ in range(n)]
on[0][0] = True
lit = 1
visited = [[False]*n for _ in range(n)]

def connected(x, y):
	for dx, dy in [[0,1], [0,-1], [1,0], [-1,0]]:
		nx, ny = x+dx, y+dy
		if nx < 0 or ny < 0 or nx == n or ny == n:
			continue
		if visited[nx][ny]:
			return True
	return False

q = collections.deque()
q.append((0,0))
while q:
	x, y = q.popleft()
	if x < 0 or y < 0 or x == n or y == n or visited[x][y] or not on[x][y]:
		continue
	if not connected(x,y) and not (x == 0 and y == 0):
		continue
	visited[x][y] = True
	for dx, dy  in [[0,1], [0,-1], [1,0], [-1,0]]:
		q.append((x+dx, y+dy))
	
	if (x,y) in lights:
		for lx, ly in lights[(x,y)]:
			if not on[lx][ly]:
				lit += 1
			on[lx][ly] = True
			q.append((lx, ly))


print(lit)
	