import sys
input = sys.stdin.readline
for _ in range(int(input())):
	n = int(input())
	sys.stdout.write("1 ")
	for i in range(n-1): sys.stdout.write(str(i%3+1) + ' ')
	sys.stdout.write("\n")