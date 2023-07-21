import sys, math

input = sys.stdin.readline

def solve():
	n, c = map(int, input().split())
	s = [int(i) for i in input().split()]
	for i in range(n):
		c -= s[i]*s[i]
	x = 4*n
	y = 0
	for i in s:
		y += i*4
	z = c* -1
	
	dis = y * y - 4 * x * z
	sqrt_val = int(math.sqrt(abs(dis)))
	if dis > 0:
		print(max((-y + sqrt_val)//(2 * x), (-y - sqrt_val)//(2 * x)))
     
	elif dis == 0:
		print(-y // (2 * x))

for _ in range(int(input())):
	solve()