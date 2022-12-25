import sys

sys.stdin = open('breedflip.in', 'r')
sys.stdout = open('breedflip.out', 'w')
input = sys.stdin.readline

n = int(input())
a = input().strip()
b = input().strip()

ans = 0
curr_diff = False
for i in range(n):
    if a[i] != b[i]:
        if not curr_diff:
            ans += 1
            curr_diff = True
    else:
        curr_diff = False

print(ans)