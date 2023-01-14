import sys

input = sys.stdin.readline

def solve(a, b):
    count = 0
    while a > b:
        if a % 2:
            a += 1
        else:
            a //= 2
        count += 1
    
    if a == b:
        return count;
    if a+1 == b:
        return count + 1
    if b % 2:
        return count+solve(a, b-1)+1
    else:
        return count+min(b-a, solve(a, b//2)+1)

for _ in range(int(input())):
    a, b = map(int, input().split())
    print(solve(a, b))