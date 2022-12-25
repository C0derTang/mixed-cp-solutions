import sys

sys.stdin = open('whereami.in', 'r')
sys.stdout = open('whereami.out', 'w')

input = sys.stdin.readline

n = int(input())
road = input().strip()

ans = n
for k in range(1, n+1):
    val = True
    for i in range(n-k+1):
        for j in range(i):
            if road[i:i+k] == road[j:j+k]:
                val = False
                break
    if val:
        ans = k
        break
print(ans)
