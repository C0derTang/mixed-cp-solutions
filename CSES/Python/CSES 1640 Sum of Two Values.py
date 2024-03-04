import sys

input = sys.stdin.readline

n, x = map(int, input().split())
a = sorted([(int(v), i+1) for i, v in enumerate(input().split())])

l = 0
r = n-1
found = False
while l<r:
	if a[l][0]+a[r][0] > x:
		r -= 1
	elif a[l][0]+a[r][0] < x:
		l += 1
	else:
		print(a[l][1], a[r][1])
		found = True
		break

if not found:
	print('IMPOSSIBLE')