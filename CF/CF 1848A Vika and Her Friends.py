import sys, collections

input = sys.stdin.readline

def solve():
    n, m, k = map(int, input().split())
    v = [int(i) for i in input().split()]
    friends = [[int(i) for i in input().split()] for _ in range(k)]
    for x, y in friends:
        dist = abs(x-v[0]) + abs(y-v[1])
        if dist % 2 == 0:
            print('NO')
            return
    print('YES')

for _ in range(int(input())):
    solve()