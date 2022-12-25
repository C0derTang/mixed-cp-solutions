import io, os, sys, collections

input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
#input = sys.stdin.readline

def solve():
    n, k = map(int, input().split())
    cows = input().decode().strip()

    if k == 0:
        print(n)
        print(cows)
        return

    g_i = []
    h_i = []
    for i, cow in enumerate(cows):
        if cow == 'G':
            g_i.append([max(i-k, 0), min(i+k, n-1)])
        else:
            h_i.append([max(i-k, 0), min(i+k, n-1)])
    #print(g_i, h_i)
    
    ans = ['.'] * n
    count = 0
    for g in g_i:
        max_pos = g[0]
        found = False
        for i in range(g[0], g[1]+1):
            if ans[i] == '.':
                max_pos = max(max_pos, i)
            elif ans[i] == 'G':
                found = True
                break
        if not found:
            ans[max_pos] = 'G'
            count += 1
    for h in h_i:
        max_pos = h[0]
        found = False
        for i in range(h[0], h[1]+1):
            if ans[i] == '.':
                max_pos = max(max_pos, i)
            elif ans[i] == 'H':
                found = True
                break
        if not found:
            ans[max_pos] = 'H'
            count += 1
    print(count)
    print(''.join(ans))








for _ in range(int(input())):
    solve()
