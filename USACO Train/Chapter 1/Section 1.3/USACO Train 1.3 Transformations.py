"""
ID: tanchr1
LANG: PYTHON3
TASK: transform
"""

import sys

sys.stdin = open('transform.in', 'r')
sys.stdout = open('transform.out', 'w')

input = sys.stdin.readline

n = int(input())
org = [tuple(input().strip()) for _ in range(n)]
new = [tuple(input().strip()) for _ in range(n)]

for i in range(1, 8):
    if i == 1:
        rotated = list(zip(*org[::-1]))
        if rotated == new:
            break
    elif i == 2:
        rotated2 = list(zip(*rotated[::-1]))
        if rotated2 == new:
            break
    elif i == 3:
        rotated3 = list(zip(*rotated2[::-1]))
        if rotated3 == new:
            break
    elif i == 4:
        ref = list(zip(*list(zip(*org))[::-1]))
        if ref == new:
            break
    elif i == 5:
        ref_rot = list(zip(*ref[::-1]))
        ref_rot2 = list(zip(*ref_rot[::-1]))
        ref_rot3 = list(zip(*ref_rot2[::-1]))
        if ref_rot == new or ref_rot2 == new or ref_rot3 == new:
            break
    elif i == 6:
        if org == new:
            break
print(i)