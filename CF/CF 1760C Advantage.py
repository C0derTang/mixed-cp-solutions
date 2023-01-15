import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = [int(i) for i in input().split()]
    best = max(s)
    without_best = s.copy()
    without_best.remove(best)
    second_best = max(without_best)

    ans = []
    for i in s:
        if i == best:
            ans.append(i-second_best)
        else:
            ans.append(i-best)
    print(*ans)