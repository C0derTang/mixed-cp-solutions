import sys
 
input = sys.stdin.readline
 
n, x = map(int, input().split())
a = [int(i) for i in input().split()]
 
pref = [0]*(n+1)
for i in range(n):
	pref[i+1] = (pref[i] + a[i])
 
ans = 0
hashmappuh = {}
for i in range(n+1):
	ans += hashmappuh.get(pref[i]-x, 0)
	hashmappuh[pref[i]] = hashmappuh.get(pref[i], 0) + 1
print(ans)
