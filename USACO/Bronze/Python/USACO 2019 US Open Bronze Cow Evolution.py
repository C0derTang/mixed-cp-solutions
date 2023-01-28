import sys
sys.stdin = open('evolution.in', 'r')
sys.stdout = open('evolution.out', 'w')

n = int(input())
cows = [0]*n
allchars = set()

for i in range(n):
	line = input().split()
	chars = list(line[1:])
	cows[i] = chars.copy()
	allchars.update(chars)

allchars = list(allchars)

for i in range(len(allchars)):
	for j in range(i + 1, len(allchars)):
		onlya, onlyb, both = 0, 0, 0
		for c in range(n):
			a, b = 0, 0
			for t in range(len(cows[c])):
				if cows[c][t] == allchars[i]:
					a = 1
				if cows[c][t] == allchars[j]:
					b = 1
			if a and not b: 
				onlya = 1
			if b and not a:
				onlyb = 1
			if a and b:
				both = 1
		if onlya and onlyb and both:
			print('no')
			sys.exit()
print('yes')
