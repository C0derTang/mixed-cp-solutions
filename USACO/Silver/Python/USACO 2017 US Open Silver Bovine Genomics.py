import sys

sys.stdin = open('cownomics.in', 'r')
sys.stdout = open('cownomics.out', 'w')

input = sys.stdin.readline

n, m = map(int, input().split())
spots = [input().strip() for _ in range(n)]
plain = [input().strip() for _ in range(n)]

ans = 0
for i in range(m):
    for j in range(i+1, m):
        for k in range(j+1, m):
            dup = set()
            val = True
            for x in range(n):
                dup.add(spots[x][i] + spots[x][j] + spots[x][k])
            for x in range(n):
                if plain[x][i] + plain[x][j] + plain[x][k] in dup:
                    val = False
                    break
            if val:
                ans += 1
sys.stdout.write(str(ans) + '\n')
