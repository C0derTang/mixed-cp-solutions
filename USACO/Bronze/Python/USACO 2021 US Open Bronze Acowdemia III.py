# PARTIAL CREDIT: TLE ON TEST CASES 5 AND 9. CPP AND JAVA PASS WITH SAME LOGIC

import sys, io, os

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

n, m = map(int, input().split())

grid = [list(input().strip()) for _ in range(n)]

poss_pairs = set()
ans = 0
for i, row in enumerate(grid):
    for j, cell in enumerate(row):
        if cell == 'G':
            nb = []
            count = 0
            for v, h in [[1,0],[-1,0],[0,1],[0,-1]]:
                if i+v < 0 or i+v >= n or j+h < 0 or j+h >= m:
                    continue
                if grid[i+v][j+h] == 'C':
                    nb.append((i+v, j+h))
                    count += 1
                    if count > 2: break
            if count == 2:
                poss_pairs.add(tuple(sorted([nb[0], nb[1]])))
            elif count > 2:
                ans += 1
            
print(len(poss_pairs)+ans)
