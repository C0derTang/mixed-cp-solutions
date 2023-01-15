import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input().strip()
    check = {c: i+1 for i, c in enumerate('abcdefghijklmnopqrstuvwxyz')}
    ans = 0
    for i in s:
        ans = max(ans, check[i])
    print(ans)