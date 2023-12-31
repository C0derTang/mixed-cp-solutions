import sys, math, collections

input = sys.stdin.readline

def solve():
	n = int(input())
	s = input().strip()
	ans = []
	vowel = 'aeiou'
	vseen = False
	for i in range(n-1, -1, -1):
		ans.append(s[i])
		if s[i] in vowel:
			vseen = True
		else:
			if vseen:
				vseen = False
				ans.append('.')
	print(''.join(ans[-2::-1]))

for _ in range(int(input())):
	solve()
