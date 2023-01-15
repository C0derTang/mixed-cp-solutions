"""
ID: tanchr1
LANG: PYTHON3
TASK: barn1
"""

import sys

sys.stdin = open('barn1.in', 'r')
sys.stdout = open('barn1.out', 'w')

input = sys.stdin.readline

m, s, c = map(int, input().split())
occ_stalls = sorted([int(input()) for _ in range(c)])

diffs = [0]*(c-1)
for i in range(c-1):
    diffs[i] = occ_stalls[i+1]-occ_stalls[i]

org_idx = {d:i for i, d in enumerate(diffs)}
diffs.sort(reverse=True)
max_diffs = sorted([org_idx[d] for d in diffs[:m-1]])

if m == 1:
    ans = occ_stalls[-1] - occ_stalls[0] + 1
elif m == len(occ_stalls):
    ans = c
else:
    ans = occ_stalls[max_diffs[0]]-occ_stalls[0]+1
    for i in range(1, len(max_diffs)):
        ans += occ_stalls[max_diffs[i]]-occ_stalls[max_diffs[i-1]+1]+1
    ans += occ_stalls[-1]-occ_stalls[max_diffs[-1]+1]+1
print(ans)
