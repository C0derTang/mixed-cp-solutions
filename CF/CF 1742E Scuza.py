import sys

input = sys.stdin.readline

def solve():
    n, q = map(int, input().split())
    a = [int(i) for i in input().split()]
    k = [int(i) for i in input().split()]
    
    prefix_sum = [0] * (n+1)
    for i in range(n):
        prefix_sum[i+1] = prefix_sum[i] + a[i]

    prefix_max = [0] * n
    cur_max = 0
    for i in range(n):
        cur_max = max(cur_max, a[i])
        prefix_max[i] = cur_max

    ans = [0] * q
    for i in range(q):
        l, r = 0, n-1
        while l < r:
            m = (l+r)//2
            if prefix_max[m] > k[i]:
                r = m
            else:
                ans[i] = prefix_sum[m+1]
                l = m+1
        if prefix_max[l] <= k[i]:
            ans[i] = prefix_sum[l+1]
                

    return " ".join([str(i) for i in ans])
        

for _ in range(int(input())):
    sys.stdout.write(solve()+'\n')
