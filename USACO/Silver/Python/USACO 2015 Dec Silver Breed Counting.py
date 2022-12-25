import sys

sys.stdin = open('bcount.in', 'r')
sys.stdout = open('bcount.out', 'w')

input = sys.stdin.readline

n, q = map(int, input().split())

a = [int(input()) for _ in range(n)]

ph, pg, pj = [0] * (n+1), [0] * (n+1), [0] * (n+1)

for i in range(n):
    ph[i+1] = ph[i]
    pg[i+1] = pg[i]
    pj[i+1] = pj[i]
    if a[i] == 1:
        ph[i+1] += 1
    elif a[i] == 2:
        pg[i+1] += 1
    else:
        pj[i+1] += 1

for _ in range(q):
    l, r = map(int, input().split())
    l -= 1
    print(ph[r]-ph[l], pg[r]-pg[l], pj[r]-pj[l])