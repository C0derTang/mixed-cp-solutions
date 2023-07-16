import sys

input = sys.stdin.readline

def solve():
	n, k = map(int, input().split())
	c = [int(i)-1 for i in input().split()]

	last = [-1]*k
	max_gap = [0] * k
	gaps = [[0] for _ in range(k)]

	for i in range(n):
		cur_max = gaps[c[i]][max_gap[c[i]]]
		if i - last[c[i]]-1 > cur_max:
			max_gap[c[i]] = len(gaps[c[i]])
		gaps[c[i]].append(i - last[c[i]]-1)
		last[c[i]] = i

	for j in range(k):
		cur_max = gaps[j][max_gap[j]]
		if i - last[j] > cur_max:
			max_gap[j] = len(gaps[j])
		gaps[j].append(i - last[j])

	ans = float('inf')
	for i in range(k):
		gaps[i][max_gap[i]] //=2
		ans = max(0, min(ans, max(gaps[i])))
	print(ans)

for _ in range(int(input())):
	solve()