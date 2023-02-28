import sys, collections

input = sys.stdin.readline

def solve():
    s = input().strip()
    if len(s) < 3:
        print(-1)
        return
    if 'MOO' in s:
        print(len(s)-3)
        return
    
    poss = False
    max_edits = False
    for i in range(len(s)-2):
        if s[i+1] == 'O':
            if s[i] == 'O' and s[i+2] == 'M':
                max_edits = True
            else:
                poss = True
    if not poss:
        if max_edits:
            print(len(s)-1)
        else:
            print(-1)
    else:
        print(len(s)-2)
                
    



for i in range(int(input())):
    solve()