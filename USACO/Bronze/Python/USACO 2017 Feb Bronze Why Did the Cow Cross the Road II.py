import sys, collections

sys.stdin = open('circlecross.in', 'r')
sys.stdout = open('circlecross.out', 'w')

input = sys.stdin.readline

road = [ord(i)-65 for i in input().strip()]
ans = 0

def check_cross(road, gt, l, r):
    ret = 0
    check = collections.Counter(road[l+1:r])
    for k, v in check.items():
        if k > gt and v == 1:
            ret += 1
    return ret

ans = 0
for i in range(26):
    first = road.index(i)
    last = road.index(i, first+1)
    ans += check_cross(road, i, first, last)
print(ans)