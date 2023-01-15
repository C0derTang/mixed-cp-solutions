import sys
input = sys.stdin.readline

def solve():
    n = int(input())
    convo = input().strip()
    
    cnt = 0
    for c in convo:
        if c == 'Q':
            cnt += 1
        else:
            cnt -= 1
            cnt = max(0, cnt)
    
    return 'Yes' if cnt == 0 else 'No'
        

for _ in range(int(input())):
    sys.stdout.write(solve() + '\n')