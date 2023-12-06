import sys, collections

input = sys.stdin.readline

def solve():
    n = int(input())
    s = input().strip()
    if '0' not in s:
        print('NO')
    else:
        print('YES')

for _ in range(int(input())):
    solve()