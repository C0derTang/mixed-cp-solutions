"""
ID: tanchr1
LANG: PYTHON3
TASK: namenum
"""

import sys

sys.stdin = open('namenum.in', 'r')
sys.stdout = open('namenum.out', 'w')

input = sys.stdin.readline

name2num = {'A':2, 'B':2, 'C':2, 'D':3, 'E':3, 'F':3, 'G':4, 'H':4, 'I':4, 'J':5, 'K':5, 'L':5, 'M':6, 'N':6, 'O':6, 'P':7, 'R':7, 'S':7, 'T':8, 'U':8, 'V':8, 'W':9, 'X':9, 'Y':9}

brand = input().strip()

ans = []

with open('dict.txt', 'r') as doc:
    names = doc.read().split()
    for name in names:
        poss = ''
        val = True
        for c in name:
            if c not in name2num:
                val = False
                break
            poss += str(name2num[c])
        if val and poss == brand:
            ans.append(name)
ans.sort()
for a in ans:
    print(a)
if len(ans) == 0:
    print('NONE')