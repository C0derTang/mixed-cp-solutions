def dist_sq(a, b):
	return (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2


with open("moocast.in", "r") as stdin:
	N = int(stdin.readline())
	cows = [tuple(map(int, stdin.readline().strip().split())) for _ in range(N)]

dist = {c: float("inf") for c in cows}
dist[cows[0]] = 0
m = 0
for t in range(N):
	i = min(dist, key=dist.__getitem__)
	m = max(m, dist[i])
	del dist[i]
	for j in dist:
		dist[j] = min(dist[j], dist_sq(i, j))

print(m, file=open("moocast.out", "w"))
