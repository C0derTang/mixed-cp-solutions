n, k = map(int, input().split())
dimunz = sorted([int(input()) for _ in range(n)])

sums = [0]*(n+1)
r = 0
for l in range(n):
	while r<n and dimunz[r]-dimunz[l] <= k:
		r += 1
	r -= 1
	sums[l] = r-l+1

smax = [0]*(n+1)
smax[n-1] = sums[n-1]
for i in range(n-2, -1, -1):
	smax[i] = max(sums[i], smax[i+1])

ans = 0
for i in range(n):
	ans = max(ans, sums[i] + smax[i+sums[i]])
print(ans)