import io,os, sys

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
    n, c, d = map(int, input().split())
    a = [int(i) for i in input().split()]
    a.sort(reverse = True)

    low, high = -1, d + 1
    while low < high:
        mid = (low+high+1) >> 1
        total = 0
        for i in range(d):
            id = i % (mid+1)
            if id < n:
                total += a[id]
        if total >= c:
            low = mid
        else:
            high = mid - 1
    if low == d+1:
        return 'Infinity'
    if low == -1:
        return 'Impossible'
    return str(low)
    

for _ in range(int(input())):
    sys.stdout.write(solve()+'\n')