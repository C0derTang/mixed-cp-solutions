import sys, io, os

input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

n = int(input())

gifts = [[] for _ in range(n + 1)]

for i in range(1, n + 1):
    gifts[i] = [int(x) for x in input().split()]
    while gifts[i][-1] != i:
        gifts[i].pop()

reachable = [[False] * (n + 1) for _ in range(n + 1)]

def dfs(src, cur):
    if reachable[src][cur]:
        return
    reachable[src][cur] = True
    for next_gift in gifts[cur]:
        dfs(src, next_gift)

for i in range(1, n + 1):
    dfs(i, i)

for i in range(1, n + 1):
    for preferred_gift in gifts[i]:
        if reachable[preferred_gift][i]:
            print(preferred_gift)
            break