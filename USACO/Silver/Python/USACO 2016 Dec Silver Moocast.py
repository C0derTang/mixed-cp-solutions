import sys, collections

sys.stdin = open('moocast.in', 'r')
sys.stdout = open('moocast.out', 'w')

input = sys.stdin.readline

n = int(input())

x, y, p = [0]*n, [0]*n, [0]*n
for i in range(n):
    x[i], y[i], p[i] = map(int, input().split())

adj = [[] for _ in range(n)]
for i in range(n):
    for j in range(i+1, n):
        x1, y1, p1, x2, y2, p2 = x[i], y[i], p[i], x[j], y[j], p[j]
        d = (x1-x2)**2 + (y1-y2)**2
        if d <= p1**2:
            adj[i].append(j)
        if d <= p2**2:
            adj[j].append(i)

max_nb = 0
for i in range(n):
    visited = set()
    q = collections.deque([i])
    ans = 0
    while q:
        cur = q.pop()
        if cur in visited:
            continue
        visited.add(cur)

        ans += 1
        for x in adj[cur]:
            if x not in visited:
                q.appendleft(x)
    max_nb = max(max_nb, ans)
print(max_nb)