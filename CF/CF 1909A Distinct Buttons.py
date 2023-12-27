import sys

input = sys.stdin.readline

def solve():
    n = int(input())
    points = [[int(i) for i in input().split()] for _ in range(n)]
    points.sort()
    up = down = right = left = False
    for x, y in points:
        if x > 0:
            right = True
        elif x < 0:
            left = True
        if y > 0:
            up = True
        elif y < 0:
            down = True
        if up and down and right and left:
            print('NO')
            return
    print('YES')

for _ in range(int(input())):
    solve()