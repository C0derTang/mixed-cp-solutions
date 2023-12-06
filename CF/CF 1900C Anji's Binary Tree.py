import sys

input = sys.stdin.readline 

def solve():
    n = int(input())
    s = input().strip()
    adj = [[int(i) for i in input().split()] for _ in range(n)]
    res = n
    q = [(0, 0)]
    while q:
        node, cnt = q.pop()
        l, r = adj[node] 
        if l + r == 0:
            res = min(res, cnt)
            continue
        if l:
            q.append((l-1, cnt+(s[node] != 'L')))
        if r:
            q.append((r-1, cnt+(s[node] != 'R')))
    print(res)

for _ in range(int(input())):
    solve()
