import sys, io,os

input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def get_sum(num):
    return sum(int(i) for i in str(num))

def solve():
    x, k = map(int, input().split())
    while get_sum(x) % k > 0:
        x += 1
    sys.stdout.write(str(x) + "\n")    

for _ in range(int(input())):
    solve()
