import sys

sys.stdin = open('revegetate.in', 'r')
sys.stdout = open('revegetate.out', 'w')

n, m = map(int, input().split())
A = [0] * m
B = [0] * m
for i in range(m):
    a, b = map(int, input().split())
    A[i] = min(a, b)
    B[i] = max(a, b)

ans = [0] * n
for p in range(1, n+1):
    for g in range(1, 5):
        val = True
        for j in range(m):
            if B[j] == p and ans[A[j]-1] == g:
                val = False
                break
        if val:
            break
    ans[p-1] = g
print(''.join([str(i) for i in ans]))