import sys, collections

sys.stdin = open('socdist1.in', 'r')
sys.stdout = open('socdist1.out', 'w')

input = sys.stdin.readline

n = int(input())
stalls = [True if i == '1' else False for i in input().strip()]

gaps = []
prev = 0
for i in range(n):
    if stalls[i]:
        gaps.append(i-prev)
        prev = i
gaps.append(i-prev)
'''
#print(gaps)

ans = 0
if gaps[0] > 0:
    if gaps[-1] > 0:
        ans = max(ans, min(gaps))
    else:
        ans = max(ans, min(gaps[:len(gaps)-1]))
elif gaps[-1] > 0:
    ans = max(ans, min(gaps[1:]))

for i in range(len(gaps)):
    if gaps[i] // 2 == 0: continue
    for j in range(i+1, len(gaps)):
        if gaps[j] // 2 == 0: continue
        ans = max(ans, gaps[i]//2, gaps[j]//2)

print(ans)

'''
def calc_dist():
    min_dist = n+1
    for i in range(n):
        if not stalls[i]:
            continue
        for j in range(i+1, n):
                if not stalls[j]:
                    continue
                min_dist = min(min_dist, j-i)
    return min_dist

ans = 0

if n <= 100:
    for i in range(n):
        if stalls[i]:
            continue
        for j in range(i+1, n):
            if stalls[j]:
                continue
            stalls[i], stalls[j] = True, True
            ans = max(ans, calc_dist())
            stalls[i], stalls[j] = False, False
else:
    if gaps[0] > 0:
        if gaps[-1] > 0:
            ans = max(ans, min(gaps))
        else:
            ans = max(ans, min(gaps[:len(gaps)-1]))
    elif gaps[-1] > 0:
        ans = max(ans, min(gaps[1:]))

    for i in range(len(gaps)):
        if gaps[i] // 2 == 0: continue
        for j in range(i+1, len(gaps)):
            if gaps[j] // 2 == 0: continue
            ans = max(ans, gaps[i]//2, gaps[j]//2)

print(ans)
