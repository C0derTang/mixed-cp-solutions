n, x = map(int, input().split())
a = [int(i) for i in input().split()]

pref = [0]*(n+1)
for i in range(n):
	pref[i+1] = pref[i]+a[i]

ans = l = 0
for r in range(n+1):
	while pref[r]-pref[l] > x:
		l += 1
	if pref[r]-pref[l] == x:
		ans += 1

print(ans)