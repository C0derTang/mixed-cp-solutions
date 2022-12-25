import sys

sys.stdin = open('hoofball.in', 'r')
sys.stdout = open('hoofball.out', 'w')

input = sys.stdin.readline

n = int(input())
cows = [int(i) for i in input().split()]
pass_to = [0] * n

def target(i):
    lnb = rnb = -1
    ldist = rdist = 1000
    for j in range(n):
        if cows[j] < cows[i] and cows[i]-cows[j] < ldist:
            lnb = j
            ldist = cows[i] - cows[j]
    for j in range(n):
        if cows[j] > cows[i] and cows[j]-cows[i] < rdist:
            rnb = j
            rdist = cows[j] - cows[i]
    if ldist <= rdist:
        return lnb
    return rnb

for i in range(n):
    pass_to[target(i)] += 1

ans = 0
for i in range(n):
    if pass_to[i] == 0:
        ans += 1
    if i < target(i) and target(target(i)) == i and pass_to[i] == 1 and pass_to[target(i)] == 1:
        ans += 1

print(ans)