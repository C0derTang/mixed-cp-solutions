import sys, heapq

sys.stdin = open('helpcross.in', 'r')
sys.stdout = open('helpcross.out', 'w')

input = sys.stdin.readline

c, n = map(int, input().split())
chickens = sorted([int(input()) for _ in range(c)])
cows = sorted([tuple(map(int, input().split())) for _ in range(n)])

ans = 0
i = 0
available = []
for chick in chickens:
	while i < n and cows[i][0] <= chick:
		heapq.heappush(available, cows[i][1])
		i += 1
	while available and available[0] <chick:
		heapq.heappop(available)
	
	if available:
		ans += 1
		heapq.heappop(available)
print(ans)