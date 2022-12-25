import sys

sys.stdin = open('gymnastics.in', 'r')
sys.stdout = open('gymnastics.out', 'w')

input = sys.stdin.readline

k, n = map(int, input().split())
acts = [[int(i) for i in input().split()] for _ in range(k)]

ans = 0
for a in range(1,n+1):
    for b in range(a+1, n+1):
        cons = 0
        for act in acts:
            if act.index(a) > act.index(b):
                cons += 1
            else:
                cons -= 1
        if abs(cons) == k:
            ans += 1
print(ans)