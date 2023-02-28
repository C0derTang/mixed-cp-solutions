import sys

input = sys.stdin.readline

n = int(input())
cows = input().strip()
e = [int(i)-1 for i in input().split()]

early_g = early_h = late_g = late_h = -1

for i in range(n-1, -1, -1):
    if cows[i] == 'G':
        early_g = i
    else:
        early_h = i

for i in range(n):
    if cows[i] == 'G':
        late_g = i
    else:
        late_h = i

ans = 0
if e[early_g] >= late_g:
    for i in range(early_g):
        if i == early_h:
            continue
        if cows[i] == 'H' and e[i] >= early_g:
            ans += 1
if e[early_h] >= late_h:
    for i in range(early_h):
        if i == early_g:
            continue
        if cows[i] == 'G' and e[i] >= early_h:
            ans += 1

if ((e[early_g] >= late_g or (early_g <= early_h and e[early_g] >= early_h)) and 
    (e[early_h] >= late_h or (early_h <= early_g and e[early_h] >= early_g))):
    ans += 1
print(ans)