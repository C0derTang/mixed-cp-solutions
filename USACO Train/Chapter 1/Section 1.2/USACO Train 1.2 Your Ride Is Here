"""
ID: tanchr1
LANG: PYTHON3
TASK: ride
"""

import sys

sys.stdin = open('ride.in', 'r')
sys.stdout = open('ride.out', 'w')

input = sys.stdin.readline

comet = input().strip()
group = input().strip()
c_c = g_c = 1
for c in comet:
    c_c *= ord(c)-64
for c in group:
    g_c *= ord(c)-64

if c_c % 47 == g_c % 47:
    print('GO')
else:
    print('STAY')
