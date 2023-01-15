import io,os, sys

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
    n = int(input())
    a = [int(i) for i in input().split()]

    psum0 = [0] * (n+1)
    psum1 = [0] * (n+1)

    inv = mult = 0
    for i, x in enumerate(a):
        psum0[i+1] = psum0[i]
        psum1[i+1] = psum1[i]
        if x == 1:
            psum1[i+1] += 1
            mult += 1
        else:
            psum0[i+1] += 1
            inv += mult

    ans = inv
    for i in range(n):
        cur = inv
        if a[i] == 0:
            cur -= psum1[i]
            cur += psum0[n] - psum0[i+1]
        else:
            cur += psum1[i]
            cur -= psum0[n] - psum0[i+1]
        ans = max(ans, cur)

    return str(ans)

for _ in range(int(input())):
    sys.stdout.write(solve()+'\n')