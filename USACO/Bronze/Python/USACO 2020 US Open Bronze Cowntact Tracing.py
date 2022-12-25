import sys

sys.stdin = open('tracing.in', 'r')
sys.stdout = open('tracing.out', 'w')

input = sys.stdin.readline

class Shake():
    def __init__(self, t, x, y):
        self.t = t
        self.x = x-1
        self.y = y-1

n, t = map(int, input().split())
final = [int(i) for i in input().strip()]

shakes = [None] * t
for i in range(t):
    time, x, y = map(int, input().split())
    shakes[i] = Shake(time, x, y)
shakes.sort(key = lambda s: s.t)

'''
for i in shakes:
    print(i.t, i.x, i.y)
print()
'''

poss_z = 0
dup = set()
min_k, max_k = t+1, -1
for p_z in range(n):
    for k in range(t+1, -1, -1):
        cows = [0] * n
        k_count = [0] * n
        cows[p_z] = 1
        for shake in shakes:
            if cows[shake.x] == 1 and cows[shake.y] == 1:
                k_count[shake.x] += 1
                k_count[shake.y] += 1
            elif cows[shake.x] == 1:
                if k_count[shake.x] < k:
                    k_count[shake.x] += 1
                    cows[shake.y] = 1
            elif cows[shake.y] == 1:
                if k_count[shake.y] < k:
                    k_count[shake.y] += 1
                    cows[shake.x] = 1 

        if cows == final:
            min_k = min(min_k, k)
            max_k = max(max_k, k)
            if p_z not in dup:
                poss_z += 1
                dup.add(p_z)

if min_k == t+1:
    min_k = 'Infinity'
if max_k == t+1:
    max_k = 'Infinity'
print(poss_z, min_k, max_k)