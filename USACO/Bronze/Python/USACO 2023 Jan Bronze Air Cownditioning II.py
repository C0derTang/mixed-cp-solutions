import sys, collections, itertools

input = sys.stdin.readline

n, m = map(int, input().split())

temps = [0] * 100
for _ in range(n):
    s, t, c = map(int, input().split())
    for i in range(s-1, t):
        temps[i] = c
conds = [None] * m
for i in range(m):
    conds[i] = [int(i) for i in input().split()]

min_cost = sys.maxsize
for i in range(1,m+1):
    for comb in itertools.combinations(list(range(m)), i):
        test = temps.copy()
        cost = 0
        for ac in comb:
            for stall in range(conds[ac][0]-1, conds[ac][1]):
                test[stall] -= conds[ac][2]
                test[stall] = max(test[stall], 0)
            cost += conds[ac][3]
        if sum(test) == 0:
            min_cost = min(min_cost, cost)
print(min_cost)
        

