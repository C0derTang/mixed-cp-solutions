import sys, math
 
input = sys.stdin.readline
 
def solve():
    n, p, l, t = map(int, input().split())
    # n days
    # p points
    # l points for less
    # t points for task
    poss_tasks = math.ceil(n/7)
    left, right = 0, n
    while left <= right:
        mid = (left+right) // 2
        if (mid*l + min(poss_tasks, 2*mid)*t) >= p:
            right = mid-1
        else:
            left = mid+1
    print(n-left)
 
 
for _ in range(int(input())):
    solve()

