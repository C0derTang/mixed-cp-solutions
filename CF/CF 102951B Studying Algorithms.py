import sys

input = sys.stdin.readline

n, x = map(int, input().split())
a = sorted([int(i) for i in input().split()], reverse=True)

ans = 0
while a and x > 0:
	cur = a.pop()
	if x - cur < 0:
		break
	ans += 1
	x -= cur

print(ans)