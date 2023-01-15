"""
ID: tanchr1
LANG: PYTHON3
TASK: milk
"""

import sys

sys.stdin = open('milk.in', 'r')
sys.stdout = open('milk.out', 'w')

input = sys.stdin.readline

n, m = map(int, input().split())
milk = {}
for _ in range(m):
    p, a = map(int, input().split())
    if p not in milk:
        milk[p] = 0
    milk[p] += a

amt = 0
for p in sorted(milk.keys()):
    if n <= 0:
        break
    while n > 0 and milk[p] > 0:
        amt += p
        milk[p] -= 1
        n -= 1
print(amt)
