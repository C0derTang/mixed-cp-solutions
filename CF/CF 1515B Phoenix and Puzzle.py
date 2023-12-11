import math

for _ in range(int(input())):
	x = int(input())
	print('YES' if x > 1 and math.sqrt(x/2) == int(math.sqrt(x/2)) or math.sqrt(x/4) == int(math.sqrt(x/4)) else 'NO')