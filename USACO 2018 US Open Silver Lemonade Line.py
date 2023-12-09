import sys

sys.stdin = open('lemonade.in', 'r')
sys.stdout = open('lemonade.out', 'w')

input = sys.stdin.readline

n = int(input())
line = sorted([int(i) for i in input().split()], reverse=True)

ans = 0
for i, c in enumerate(line):
	if c >= ans:
		ans += 1
print(ans)