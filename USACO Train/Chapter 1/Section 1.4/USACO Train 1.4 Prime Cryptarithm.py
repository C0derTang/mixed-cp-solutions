"""
ID: tanchr1
LANG: PYTHON3
TASK: crypt1
"""

import sys

sys.stdin = open('crypt1.in', 'r')
sys.stdout = open('crypt1.out', 'w')

input = sys.stdin.readline

n = int(input())
digits = set(i for i in input().split())

ans = 0
for h1 in digits:
    for t1 in digits:
        for o1 in digits:
            for t2 in digits:
                for o2 in digits:
                    val = True

                    pp1 = int(h1+t1+o1) * int(o2)
                    pp2 = int(h1+t1+o1) * int(t2)
                    if len(str(pp1)) != 3 or len(str(pp2)) != 3:
                        continue

                    for i in str(pp1):
                        if i not in digits:
                            val = False
                            break
                    for i in str(pp2):
                        if i not in digits:
                            val = False
                            break
                    res = pp1+(pp2*10)

                    for i in str(res):
                        if i not in digits:
                            val = False
                            break
                    if val:
                        ans += 1
print(ans)