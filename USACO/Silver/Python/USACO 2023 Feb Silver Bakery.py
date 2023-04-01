import sys

input = sys.stdin.readline

def solve():
    n, tc, tm = map(int, input().split())
    a, b, c = [0]*n, [0]*n, [0]*n
    for i in range(n):
        a[i], b[i], c[i] = map(int, input().split())

    def check(w):
        d = tc+tm-w
        lx, hx = max(1, tc-w), min(tc, tc+tm-w-1)
        for i in range(n):
            if b[i] > a[i]:
                lx = max(lx, (-c[i] + b[i] * d + (b[i] - a[i] - 1)) // (b[i] - a[i]))
            elif a[i] > b[i]:
                hx = min(hx, (c[i] - b[i] * d) // (a[i] - b[i]))
            else:
                if a*d > c:
                    return False
        return lx <= hx
    low, high = 0, tc+tm-2
    while high > low:
        mid = (low+high)//2
        if check(mid):
            high = mid
        else:
            low = mid+1
    print(low)

for _ in range(int(input())):
    input()
    solve()
