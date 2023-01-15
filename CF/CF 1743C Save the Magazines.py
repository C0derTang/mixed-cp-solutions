import io,os, sys
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def solve():
    n = int(input())
    lids = [int(i) for i in input().strip()]
    vals = [int(i) for i in input().split()]
    
    recent_zero = None
    for i in range(n):
        if lids[i] == 0:
            recent_zero = i
        else:
            if recent_zero != None and vals[i] < vals[recent_zero]:
                lids[i] = 0
                lids[recent_zero] = 1
                recent_zero = i
    
    ans = 0
    for i in range(n):
        if lids[i] == 1:
            ans += vals[i]
    return str(ans)
 
for _ in range(int(input())):
    sys.stdout.write(solve() + '\n')
