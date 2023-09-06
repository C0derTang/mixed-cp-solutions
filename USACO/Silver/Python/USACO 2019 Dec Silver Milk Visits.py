import sys

sys.stdin = open('milkvisits.in', 'r')
sys.stdout = open('milkvisits.out', 'w')

input = sys.stdin.readline

n, m = map(int, input().split())

cows = input().strip()
neighbors = [[] for _ in range(n)]
for _ in range(n-1):
    f1, f2 = map(int, input().split())
    neighbors[f1-1].append(f2-1)
    neighbors[f2-1].append(f1-1)

cur_comp = 0
comps = [-1 for _ in range(n)]
for i in range(n):
    if comps[i] != -1:
        continue
    new = [i]
    cur_type = cows[i]
    while new:
        cur = new.pop()
        comps[cur] = cur_comp
        for nb in neighbors[cur]:
            if cows[nb] == cur_type and comps[nb] == -1:
                new.append(nb)
    cur_comp += 1

ans = ''
for _ in range(m):
    a, b, t = map(str, input().split())
    a = int(a) - 1
    b = int(b) - 1
    if comps[a] == comps[b]:
        if t == cows[a]:
            ans += '1'
        else:
            ans += '0'
    else:
        ans += '1'
print(ans)