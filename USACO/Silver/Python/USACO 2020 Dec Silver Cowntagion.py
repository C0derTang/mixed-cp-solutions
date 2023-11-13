import sys, collections

input = sys.stdin.readline

n = int(input())

adj = [0]*n
for _ in range(n-1):
    a, b = map(int, input().split())
    adj[a-1]+= 1
    adj[b-1]+= 1

ans = n-1
for i in range(n):
    if adj[i] > 1 or i == 0:
        children = adj[i]
        if i != 0: children -= 1
        logchild = 0
        ex = 1
        while ex < children+1:
            logchild += 1
            ex *= 2
        ans += logchild

print(ans)
