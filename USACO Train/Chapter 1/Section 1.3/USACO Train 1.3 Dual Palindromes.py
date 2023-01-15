"""
ID: tanchr1
LANG: PYTHON3
TASK: dualpal
"""

import sys

sys.stdin = open('dualpal.in', 'r')
sys.stdout = open('dualpal.out', 'w')

input = sys.stdin.readline

DIGITS = '0123456789ABCDEFGHIJKLMNOP'
def change_base(num, base):
    stack = []
    while num > 0:
        rem = num % base
        stack.append(rem)
        num //= base
    ret = []
    while stack:
        ret.append(DIGITS[stack.pop()])

    return ''.join(ret)

n, s = map(int, input().split())

while n > 0:
    cur = s+1
    p_count = 0
    for b in range(2, 11):
        if change_base(cur, b) == change_base(cur, b)[::-1]:
            p_count += 1
    if p_count > 1:
        n -= 1
        print(cur)
    s += 1