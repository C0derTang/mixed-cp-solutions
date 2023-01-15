import io,os, sys
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
    n = int(input())
    a = [int(i) for i in input().split()]
    l = 0
    found = False
    cur_a = set()
    for r in range(n):
        cur_a.add(a[r])
        if len(cur_a) > 1:
            l = r
            cur_a = set()
        cur_a.add(a[r])
        if (l == 0 or a[l-1] > a[l]) and (r == n-1 or a[r] < a[r+1]):
            #print(l, r)
            if found:
                return 'NO\n'
            else:
                found = True
        #print(l, r, cur_a)
    return 'YES\n' if found else'NO\n'

for _ in range(int(input())):
    sys.stdout.write(solve())
