import sys

input = sys.stdin.readline

n = int(input())
g_or_l = [None] * n
places = [None] * n

for i in range(n):
    g_l, pos = map(str, input().split())
    g_or_l[i] = g_l
    places[i] = int(pos)

min_liars = n
for pos in places:
    cur_liars = 0
    for i in range(n):
        if places[i] == pos:
            continue
        if g_or_l[i] == 'G' and pos < places[i]:
            cur_liars += 1
        elif g_or_l[i] == 'L' and pos > places[i]:
            cur_liars += 1
    min_liars = min(cur_liars, min_liars)

print(min_liars)