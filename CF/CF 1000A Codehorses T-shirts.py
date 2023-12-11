n = int(input())

ts = ['S','M','L','XS','XXS','XXXS','XL','XXL','XXXL']

a = {i:0 for i in ts}
b = {i:0 for i in ts}

for _ in range(n):
	a[input().strip()] += 1
for _ in range(n):
	b[input().strip()] += 1

ans = 0
for k in a.keys():
	ans += abs(b[k]-a[k])

print(ans//2)