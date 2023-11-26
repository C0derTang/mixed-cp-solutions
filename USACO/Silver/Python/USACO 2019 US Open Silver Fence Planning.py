import sys

sys.stdin = open('fenceplan.in', 'r')
sys.stdout = open('fenceplan.out', 'w')

input = sys.stdin.readline

class Cow:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

n, m = map(int, input().split())
cows = [Cow() for _ in range(n)]
for i in range(n):
    cows[i].x, cows[i].y = map(int, input().split())

adj = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    adj[a-1].append(b-1)
    adj[b-1].append(a-1)

min_per = float('inf')

visited = [False]*n
for i in range(n):
    if visited[i]:
        continue
    
    maxx = maxy = 0
    minx = miny = float('inf')
    stack = [i]
    while stack:
        cur = stack.pop()
        visited[cur] = True
        maxx = max(maxx, cows[cur].x)
        minx = min(minx, cows[cur].x)
        maxy = max(maxy, cows[cur].y)
        miny = min(miny, cows[cur].y)
        for j in adj[cur]:
            if not visited[j]:
                stack.append(j)
    
    min_per = min(min_per, 2*(maxx - minx) + 2*(maxy - miny))
    
print(min_per)
