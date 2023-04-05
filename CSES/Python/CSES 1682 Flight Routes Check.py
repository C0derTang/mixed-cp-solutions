import sys

input = sys.stdin.readline

n, m = map(int, input().split())

forward_adj = [[] for _ in range(n)]
reverse_adj = [[] for _ in range(n)]

for _ in range(m):
    to, fro = map(int, input().split())
    forward_adj[to-1].append(fro-1)
    reverse_adj[fro-1].append(to-1)

def dfs(graph):
    unvisited = set(range(1, n))
    stack = [0]
    while stack:
        cur = stack.pop()
        for adj in graph[cur]:
            if adj in unvisited:
                stack.append(adj)
                unvisited.remove(adj)
    return unvisited

visited = dfs(forward_adj)
visitors = dfs(reverse_adj)

if visited:
    print('NO')
    print(1, visited.pop()+1)
elif visitors:
    print('NO')
    print(visitors.pop()+1, 1)
else:
    print('YES')