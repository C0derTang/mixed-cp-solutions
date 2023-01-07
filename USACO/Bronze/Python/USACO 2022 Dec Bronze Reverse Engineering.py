import io, os, sys

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    inputs = [None] * m
    outputs = [None] * m
    tcPassed = [False] * m
    for i in range(m):
        ip, ret = map(str, input().split())
        inputs[i] = ip
        outputs[i] = ret
    while True:
        found = False
        for bit in range(n):
            if found: break
            for val in '01':
                if found: break
                for output in '01':
                    if found: break
                    consistent = True
                    one = False
                    for tc in range(m):
                        if tcPassed[tc]: continue

                        if inputs[tc][bit] == val:
                            one = True
                            if outputs[tc] != output:
                                consistent = False
                    if consistent and one:
                        found = True
                        for tc in range(m):
                            if tcPassed[tc]: continue
                            if inputs[tc][bit] == val:
                                tcPassed[tc] = True
        if not found: break
    ok = True
    for i in range(m):
        if not tcPassed[i]:
            ok = False
            break
    if ok:
        print('OK')
    else:
        print('LIE')

for _ in range(int(input())):
    input()
    solve()
