import io, os, sys

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

n = int(input())
towers = [None] * n
total = []
for i in range(n):
    tower = [int(x) for x in input().split()][1:]
    towers[i] = tower.copy()
    total.extend(tower)
#print(towers)

total.sort()
total_ind = {v:i for i, v in enumerate(total)}
#print(total_ind)

splits = 0
for tower in towers:
    for i in range(len(tower)-1):
        if total_ind[tower[i]] != total_ind[tower[i+1]]-1:
            splits += 1

print(splits, n+splits-1)