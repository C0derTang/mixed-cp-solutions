import sys, bisect

input = sys.stdin.readline

g, n = map(int, input().split())

def read():
    x, y, t = map(int, input().split())
    return [t, x, y]

grazings = sorted([read() for _ in range(g)])

ans = 0
for _ in range(n):
    alibi = read()
    pos = bisect.bisect(grazings, alibi)
    innocent = False
    for i in range(pos-1, pos+1):
        if 0 <= i < g:
            gt, gx, gy = grazings[i]
            ct, cx, cy = alibi
            innocent |= (cx-gx)**2 + (cy-gy)**2 > (ct-gt)**2
    if innocent:
        ans += 1
print(ans)