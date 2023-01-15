import sys, io, os

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
    n, a, b = map(int, input().split())
    if n == a == b:
        return True
    return n-a-b >= 2

for _ in range(int(input())):
    if solve():
        sys.stdout.write('Yes\n')
    else:
        sys.stdout.write('No\n')