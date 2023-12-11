n = int(input())
l = [0] * 1001

for i in input().split():
	l[int(i)] += 1


print(max(l), len([i for i, a in enumerate(l) if a != 0]))