import sys
input = sys.stdin.readline

n = int(input())
a = [0]*100
for _ in range(n):
	a[int(input())-1] += 1
if a.count(0) == 98 and len(set(a)) == 2:
	print('YES')
	v1 = v2 = 0
	for i in range(100):
		if a[i] != 0:
			if v1 == 0:
				v1 = i+1
			else:
				v2 = i+1
	print(v1, v2)
else:
	print('NO')