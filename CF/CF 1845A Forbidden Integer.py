import sys, io, os, collections

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
	n, k, x = map(int, input().split())
	if k == 1:
		print('NO')
		return
	if k == 2 and x == 1:
		if n % 2 == 0:
			print('YES')
			print(n//2)
			print(*[2]*(n//2))
		else:
			print('NO')
		return

	val = True
	
	if x == 1:
		if n % 2 == 0:
			print('YES')
			print(n//2)
			print(*[2]*(n//2))
		else:
			print('YES')
			print(n//2)
			print(*[2]*(n//2-1)+[3])
	else:
		print('YES')
		print(n)
		print(*[1]*n)

for _ in range(int(input())):
	solve()