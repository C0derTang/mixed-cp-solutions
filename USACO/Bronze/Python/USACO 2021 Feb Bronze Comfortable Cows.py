import io, os, sys
#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

field = [[0]*1001 for _ in range(1001)]
n = int(input())

comf_loc = set()
for _ in range(n):
    x, y = map(int, input().split())
    field[x][y] = 1
    
    for h, v in ((0,0),(1,0),(0,1),(-1,0),(0,-1)):
        t_x, t_y = x+h, y+v
        if t_x < 0 or t_x >= 1000 or t_y < 0 or t_y >= 1000 or field[t_x][t_y] == 0:
            continue
        surr = 0
        for h2, v2 in ((1,0),(0,1),(-1,0),(0,-1)):
            if t_x+h2 < 0 or t_x+h2 >= 1000 or t_y+v2 < 0 or t_y+v2 >= 1000:
                continue
            if field[t_x + h2][t_y + v2] == 1:
                surr += 1
        if surr == 3:
            comf_loc.add((t_x, t_y))
        elif surr == 4:
            if (t_x, t_y) in comf_loc:
                comf_loc.remove((t_x, t_y))

    sys.stdout.write(str(len(comf_loc)) + '\n')