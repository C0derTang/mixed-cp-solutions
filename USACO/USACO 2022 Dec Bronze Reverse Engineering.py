import io, os, sys, collections, itertools

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    ips = [None] * m
    rets = [None] * m
    for i in range(m):
        ip, ret = map(str, input().split())
        ret = int(ret)
        ips[i] = ip
        rets[i] = ret

    programs = [i for i in range(m)]
    
    while True:
        updated = False
        for i in range(n):
            if updated:
                break
            offvals = set()
            offinputs = []
            onvals = set()
            oninputs = []
            for j in programs:
                if ips[j][i] == '1':
                    onvals.add(rets[j])
                    oninputs.append(j)
                else:
                    offvals.add(rets[j])
                    offinputs.append(j)
            print(offvals, onvals, offinputs, oninputs)
                    
            if len(offvals) <= 1 and len(onvals) <= 1:
                print("OK")
                return
            if len(offvals) == 0 or len(onvals) == 0:
                continue
            if len(offvals) == 2 and len(onvals) == 2:
                continue
            if len(offvals) == 1:
                updated = True
                programs = oninputs
            elif len(onvals) == 1:
                updated = True
                programs = offinputs
        if not updated:
            print("LIE")
            return

for _ in range(int(input())):
    input()
    solve()
