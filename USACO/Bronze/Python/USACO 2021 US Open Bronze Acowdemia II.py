import sys

input = sys.stdin.readline

k, n = map(int, input().split())
p_order = {p:i for i, p in enumerate(input().split())}
ans = [['?']*n for _ in range(n)]

for a in range(n):
    ans[a][a]= 'B'

for _ in range(k):
    pub = input().split()
    for i in range(n):
        ab = True
        for j in range(i+1, n):
            if pub[j-1] > pub[j]:
                ab = False
            if not ab:
                a = p_order[pub[i]]
                b = p_order[pub[j]]
                ans[a][b] = '0'
                ans[b][a] = '1'

for a in ans:
    print(''.join(a))
