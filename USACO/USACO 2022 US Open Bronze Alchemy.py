import io, os, sys, collections

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

n = int(input())
a = [int(i) for i in input().split()]
k = int(input())
need = [[]for _ in range(n)]
for _ in range(k):
    line = [int(i) for i in input().split()]
    r, l, m = line[0], line[1], line[2:]
    need[r-1] = [i-1 for i in m]

ans = 0
while True:
    consume = [0] * n
    consume[-1] += 1
    good = True
    for i in range(n-1, -1, -1):
        if consume[i] <= a[i]:
            a[i] -= consume[i]
            continue
        if len(need[i]) == 0:
            good = False
            break
        take = min(consume[i], a[i])
        consume[i] -= take
        a[i] -= take
        for out in need[i]:
            consume[out] += consume[i]
    if good:
        ans += 1
    else:
        break
print(ans)