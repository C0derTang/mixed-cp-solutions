import sys
input = sys.stdin.readline

def solve():
    s = input().strip()

    new_s = ''
    prev = s[0]
    for c in s:
        if prev != c:
            new_s += prev
            prev = c
    new_s += prev

    check = 0
    for i in range(len(new_s)-1):
        check += get_dir(new_s[i], new_s[i+1])
    return 'CW' if check > 0 else 'CCW'

def get_dir(d1, d2):
    if d1 == 'N':
        return 1 if d2 == 'E' else -1
    elif d1 == 'E':
        return 1 if d2 == 'S' else -1
    elif d1 == 'S':
        return 1 if d2 == 'W' else -1
    else:
        return 1 if d2 == 'N' else -1

for _ in range(int(input())):
    sys.stdout.write(solve()+'\n')

