import sys

input = sys.stdin.readline

n = int(input())

h = [int(i) for i in input().split()]
adj = [set() for _ in range(n)]
for _ in range(n-1):
    a, b = map(int, input().split())
    adj[a-1].add(b-1)
    adj[b-1].add(a-1)

target_sum = sum(h)//n

take, give, = [], []

leaves = set(i for i in range(n) if len(adj[i]) == 1)
while leaves:
    parents = set()
    for i in leaves:
        if len(adj[i]) == 1:
            neighbor = adj[i].pop()
            if h[i] > target_sum:
                take.append((i+1, neighbor+1, h[i]-target_sum))
            elif h[i] < target_sum:
                give.append((neighbor+1, i+1, target_sum-h[i]))
            h[neighbor] -= target_sum-h[i]
            adj[neighbor].remove(i)
            parents.add(neighbor)
    leaves = parents.copy()
give.reverse()
ans = take + give
print(len(ans))
for a in ans:
    print(*a)