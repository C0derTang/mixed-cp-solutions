import sys

input = sys.stdin.readline
sys.setrecursionlimit(1000000)

n, m = map(int, input().split())
connect = [set() for _ in range(n+1)]
for _ in range(m):
    c1, c2 = map(int, input().split())
    connect[c1].add(c2)
    connect[c2].add(c1)

unvisited = set(range(1, n+1))
starts = set()

def dfs(cur):
    q = [cur]
    while q:
        cur = q.pop()
        for nxt in connect[cur]:
            if nxt in unvisited:
                unvisited.remove(nxt)
                q.append(nxt)

while unvisited:
    start = unvisited.pop()
    starts.add(start)
    dfs(start)

print(len(starts)-1)
root = starts.pop()
for other in starts:
    print(root, other)
    