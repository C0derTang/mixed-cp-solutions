import heapq, sys

input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    adj = [[] for _ in range(n)]
    for _ in range(m):
        u, v, w = map(int, input().split())
        adj[u-1].append((v-1, w))
        adj[v-1].append((u-1, w))
    slowness = [int(i) for i in input().split()]
    
    dist = [float('inf')]*n
    best_visit_bike = [float('inf')]*n
    dist[0] = 0
    pq = [(0, 0, slowness[0])]
    while pq:
        curdist, curnode, curbike = heapq.heappop(pq)
        if curbike < best_visit_bike[curnode]:
            best_visit_bike[curnode] = curbike
            for nb, w in adj[curnode]:
                if curdist + w*curbike < dist[nb] or (curbike < best_visit_bike[nb] and curbike < slowness[nb]):
                    dist[nb] = min(dist[nb], curdist + w*curbike)
                    heapq.heappush(pq, (curdist+w*curbike, nb, min(curbike, slowness[nb])))
    print(dist[-1])

for _ in range(int(input())):
    solve()