import sys

sys.stdin = open('crossroad.in', 'r')
sys.stdout = open('crossroad.out', 'w')

input = sys.stdin.readline

n = int(input())
count = {}
ans = 0
for _ in range(n):
    cow, side = map(int, input().split())
    if cow in count and side != count[cow]:
        ans += 1
    count[cow] = side
print(ans)