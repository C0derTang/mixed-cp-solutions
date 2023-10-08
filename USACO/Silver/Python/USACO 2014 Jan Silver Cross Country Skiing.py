# Python TLE on test cases 5 7 8 9 10

import sys, collections

sys.stdin = open('ccski.in', 'r')
sys.stdout = open('ccski.out', 'w')

input = sys.stdin.readline

m, n = map(int, input().split())
course = [[int(i) for i in input().split()] for _ in range(m)]
waypoints = []
for i in range(m):
    for j, v in enumerate(input().split()):
        if v == '1':
            waypoints.append([i, j])

def bfs(wp, dist):
    q = collections.deque()
    q.append(wp)
    visited = set()
    while q:
        curi, curj = q.popleft()
        if (curi, curj) in visited:
            continue
        visited.add((curi, curj))
        for di, dj in ((0,1), (0,-1), (1,0), (-1,0)):
            ni, nj = curi+di, curj+dj
            if ni < 0 or ni >= m or nj < 0 or nj >= n or (ni, nj) in visited or abs(course[ni][nj]-course[curi][curj]) > dist:
                continue
            q.append((ni, nj))
    for ci, cj in waypoints:
        if (ci, cj) not in visited:
            return False
    return True
        
        

minh, maxh = 1000000000, 0
for i in range(m):
    for j in range(n):
        minh = min(minh, course[i][j])
        maxh = max(maxh, course[i][j])

l, r = 0, maxh-minh+1
while l < r:
    mid = (l+r)//2
    if bfs(waypoints[0], mid):
        r = mid-1
    else:
        l = mid+1
print(l)