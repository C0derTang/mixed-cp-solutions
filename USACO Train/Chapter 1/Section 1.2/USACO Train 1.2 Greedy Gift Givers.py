"""
ID: tanchr1
LANG: PYTHON3
TASK: gift1
"""

import sys

sys.stdin = open('gift1.in', 'r')
sys.stdout = open('gift1.out', 'w')

input = sys.stdin.readline

np = int(input())
names = [input().strip() for _ in range(np)]
accs = {name:0 for name in names}
for _ in range(np):
    giver = input().strip()
    amt, p = map(int, input().split())
    if p == 0:
        continue
    accs[giver] -= amt
    for _2 in range(p):
        accs[input().strip()] += amt//p
    accs[giver] += amt % p

for name in names:
    print(name, accs[name])