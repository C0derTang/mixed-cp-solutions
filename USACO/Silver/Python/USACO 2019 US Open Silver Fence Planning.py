import sys, collections

sys.stdin = open('fenceplan.in', 'r')
sys.stdout = open('fenceplan.out', 'w')

input = sys.stdin.readline

n, m = map(int, input().split())

x, y = [0]*n, [0]*n
for i in range(n):
    x[i], y[i] = map(int, input().split())

adj = [[] for _ in range(n)]
for _ in range(m):
    c1, c2 = map(int, input().split())
    adj[c1-1].append(c2-1)
    adj[c2-1].append(c1-1)

#print(adj)

ans = sys.maxsize
visited = set()
for i in range(n):
    if i in visited:
        continue
    q = collections.deque([i])
    minx = miny = sys.maxsize
    maxx = maxy = 0
    while q:
        cur = q.pop()
        if cur in visited:
            continue
        visited.add(cur)
        minx = min(minx, x[cur])
        miny = min(miny, y[cur])
        maxx = max(maxx, x[cur])
        maxy = max(maxy, y[cur])

        for k in adj[cur]:
            if k not in visited:
                q.appendleft(k)
    ans = min(ans, (maxx-minx)*2 + (maxy-miny)*2)
print(ans)
