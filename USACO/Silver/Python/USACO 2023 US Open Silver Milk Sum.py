import sys

input = sys.stdin.readline

n = int(input())
a = [int(i) for i in input().split()]
order = [i for i in range(n)]
order.sort(key=lambda x: a[x])
pos = [0]*n
for i in range(n):
    pos[order[i]]= i
a.sort()

def b_search(x):
    low, high = 0, n
    while low < high:
        mid = (high+low)//2
        if a[mid] >= x:
            high = mid
        else:
            low = mid+1
    return low

tot = 0
pref_sum = [0] * (n+1)
for i in range(n):
    pref_sum[i+1] = pref_sum[i] + a[i]
    tot += (i+1) * a[i]

def solve():
    i, v = map(int, input().split())
    i -= 1
    i = pos[i]
    new_i = b_search(v)
    if v > a[i]:
        new_i -= 1
    ans = tot
    ans -= (i+1)*a[i]
    if new_i >= i:
        ans -= pref_sum[new_i+1] - pref_sum[i+1]
    else:
        ans += pref_sum[i] - pref_sum[new_i]
    ans += (new_i+1) * v
    print(ans)

q = int(input())
for _ in range(q):
    solve()