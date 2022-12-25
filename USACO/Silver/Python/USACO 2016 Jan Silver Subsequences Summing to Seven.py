import sys

sys.stdin = open('div7.in', 'r')
sys.stdout = open('div7.out', 'w')

input = sys.stdin.readline

n = int(input())
cows = [int(input()) for _ in range(n)]

pref = [0] * (n+1)

for i in range(n):
    pref[i+1] = pref[i] + cows[i]%7
    pref[i+1] %= 7

ans = 0
earliest = {}
for i in range(1, n+1):
    if pref[i] in earliest:
        ans = max(ans, i - earliest[pref[i]])
    else:
        earliest[pref[i]] = i

#print(cows)
#print(pref)
print(ans)