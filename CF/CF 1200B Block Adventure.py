import sys

input = sys.stdin.readline

def solve():
    n, m, k = map(int, input().split())
    h = [int(i) for i in input().split()]

    for i in range(n - 1):
        height_diff = h[i+1] - h[i]

        if height_diff > k:
            m -= height_diff - k
        else:
            m += h[i] - max(0, h[i+1] - k)

        if m < 0:
            return 'NO'

    return 'YES'

for _ in range(int(input())):
    print(solve())
