import sys

sys.stdin = open('convention.in', 'r')
sys.stdout = open('convention.out', 'w')

input = sys.stdin.readline

n, m, c = map(int, input().split())

arrival = sorted([int(i) for i in input().split()])

def can_fit(wait):
    arr_t = arrival[0]
    cur_pass = tot_pass = 0
    tempm = m
    for i, a in enumerate(arrival):
        if cur_pass == c or a-arr_t > wait:
            tempm -= 1
            tot_pass += cur_pass
            cur_pass = 0
            arr_t = a
        cur_pass += 1
    tempm -= 1   
    return tempm >= 0


l = 0
r = arrival[-1]-arrival[0]
while l <= r:
    mid = (l+r) // 2
    if can_fit(mid):
        r = mid - 1
    else:
        l = mid + 1
print(l)