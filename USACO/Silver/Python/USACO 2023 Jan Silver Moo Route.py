import sys

input = sys.stdin.readline

n = int(input())
a = [int(i) for i in input().split()]+[0]

ans = ""
i = 0
while not(i == 0 and a[i] == 0):
    while a[i] > 0:
        ans += 'R'
        a[i] -= 1
        i += 1
    while i > 0 and (a[i-1] > 1 or a[i] == 0):
        ans += 'L'
        i -= 1
        a[i] -= 1
print(ans)