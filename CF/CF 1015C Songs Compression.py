import sys, math, collections

input = sys.stdin.readline

n, m = map(int, input().split())
taken_mem = 0
diff = [0]*n
for i in range(n):
	a, b = map(int, input().split())
	taken_mem += a
	diff[i] = a-b
diff.sort()

while diff and taken_mem > m:
	taken_mem -= diff.pop()

if taken_mem > m:
	print(-1)
else:
	print(n-len(diff))