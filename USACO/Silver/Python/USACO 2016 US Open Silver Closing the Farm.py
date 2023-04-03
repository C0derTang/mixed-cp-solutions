#TLEs on 8 and 10

import sys

sys.stdin = open('closing.in', 'r')
sys.stdout = open('closing.out', 'w')

input = sys.stdin.readline

n, m = map(int, input().split())
paths = {i+1:[] for i in range(n)}

for _ in range(m):
    b1, b2 = map(int, input().split())
    paths[b1].append(b2)
    paths[b2].append(b1)

def dfs(i):
    if i in visited:
        return
    if paths[i]:
        visited.add(i)
    for x in paths[i]:
        if x not in visited:
            dfs(x)

visited = set()
dfs(1)
print('YES'if len(visited) == len(paths) else 'NO')
deleted = [True]*n
for t in range(n-1):
    rem = int(input())
    visited = set()
    paths[rem] = []
    deleted[rem-1] = False
    for i in range(n):
        if deleted[i]:
            break
    dfs(i+1)
    print('YES'if len(visited) == n-t-1 else 'NO')