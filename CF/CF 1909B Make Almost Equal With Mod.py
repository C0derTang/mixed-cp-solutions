import sys, math

input = sys.stdin.readline

def gcd (a,b):
    if (b == 0):
        return a
    else:
         return gcd (b, a % b)

def check(a, f):
    rem = set()
    for c in a:
        rem.add(c%f)
        if len(rem) > 2:
            return False
    return len(rem) == 2

def solve():
    n = int(input())
    a = [int(i) for i in input().split()]
    if len(a) == 2:
        print(max(a))
        return
    odds = evens = False
    for i in a:
        if i % 2 == 0:
            evens = True
        else:
            odds = True
        if evens and odds:
            break
    if evens and odds:
        print(2)
    else:
        res = a[0]
        for c in a[1:]:
            res = gcd(res, c)
        factor = 2
        while not check(a, res*factor):
            factor *= 2
        print(res*factor)
        

for _ in range(int(input())):
    solve()