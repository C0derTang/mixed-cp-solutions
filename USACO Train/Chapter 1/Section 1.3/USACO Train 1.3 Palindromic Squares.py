"""
ID: tanchr1
LANG: PYTHON3
TASK: palsquare
"""

import sys

sys.stdin = open('palsquare.in', 'r')
sys.stdout = open('palsquare.out', 'w')

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

b = int(input())
for i in range(1, 301):
    cur = change_base(i*i, b)
    if cur == cur[::-1]: print(change_base(i, b), cur)