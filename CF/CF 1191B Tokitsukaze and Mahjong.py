tiles = input().split()

lmao = {'m':[], 's':[], 'p':[]}
for tile in tiles: lmao[tile[1]].append(int(tile[0]))

ans=3
for v in lmao.values():
    if len(v) == 1: ans=min(ans, 2)
    else:
        seq=0
        for i,x in enumerate(sorted(v)):
            if i==0: continue
            seq += (x-sorted(v)[i-1] == 1)
        ans = min(ans, 2-seq)
        ans = min(ans, 2-(len(v)-len(set(v))))

        gap = False
        for i,x in enumerate(sorted(v)):
            if i<1: continue
            gap = (x-sorted(v)[i-1] == 2)
            if gap: break
        if gap: ans = min(ans, 1)
print(ans)
