import sys

input = sys.stdin.readline


def solve():
    n, d, h = map(int, input().split())
    y = [int(i) for i in input().split()]

    area = n*d*h/2
    for i in range(n-1):
        overlap_h = max(0, (y[i]+h) - y[i+1])
        area -= (d*overlap_h/h)*overlap_h/2

    print(area)

for _ in range(int(input())):
	solve()