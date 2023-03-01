import sys

input = sys.stdin.readline

def solve():
    before = input().strip()
    after = input().strip()
    n = len(before)

    change = {}
    for i in range(n):
        if before[i] in change and change[before[i]] != after[i]:
            print(-1)
            return
        change[before[i]] = after[i]
    if len(set(after)) == 52 and before != after:
        print(-1)
        return

    ans = 0
    in_deg = {}
    for c in ab:
        if c in change and change[c] != c:
            in_deg[change[c]] = in_deg.get(change[c], 0) + 1
            ans += 1
    seen = {}
    for c in ab:
        if c not in seen:
            a = c
            while a not in seen:
                seen[a] = c
                a = change.get(a, a)
            if a in change and a != change[a] and seen[a] == c:
                s = a
                cycle = True
                while True:
                    seen[a] = 'moo'
                    if in_deg.get(a, 0) > 1:
                        cycle = False
                    a = change[a]
                    if a == s:
                        break
                if cycle:
                    ans += 1
    print(ans)

ab = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
for _ in range(int(input())):
    solve()