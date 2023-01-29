import sys

input = sys.stdin.readline

n, q = map(int, input().split())
a = [int(i) for i in input().split()]

pref_sum = [0]* (n+1)
for i in range(n):
    pref_sum[i+1] = pref_sum[i] + a[i]


for _ in range(q):
    start, end = map(int, input().split())
    print(pref_sum[end] - pref_sum[start])
