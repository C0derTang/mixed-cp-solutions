import io, os, sys, collections
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

n, m, k = map(int, input().split())

cows = []
for _ in range(n):
    w, a = map(int, input().split())
    cows.append([w, a])
cows.sort(reverse=True)
#print(cows)

ans = 0
towers = collections.deque([[float('inf'), m]])
for w, a in cows:
    rem = a
    while len(towers) > 0 and rem > 0 and w+k <= towers[0][0]:
        if towers[0][1] > rem:
            towers[0][1] -= rem
            rem = 0
        else:
            rem -= towers[0][1]
            towers.popleft()
    if a-rem > 0:
        towers.append([w, a-rem])
        ans += a-rem
print(ans)