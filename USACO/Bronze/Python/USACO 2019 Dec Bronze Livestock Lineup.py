import sys

sys.stdin = open('lineup.in', 'r')
sys.stdout = open('lineup.out', 'w')

input = sys.stdin.readline

cows = ['Beatrice', 'Belinda', 'Bella', 'Bessie', 'Betsy', 'Blue', 'Buttercup', 'Sue']
cow_to_int = {cow:i for i, cow in enumerate(cows)}
int_to_cow = {v:k for k, v in cow_to_int.items()}

n = int(input())
neighbors = [[] for _ in range(8)]
for _ in range(n):
    line = input().split()
    neighbors[cow_to_int[line[0]]].append(cow_to_int[line[-1]])
    neighbors[cow_to_int[line[-1]]].append(cow_to_int[line[0]])

ans = []
head = [i for i in range(8) if len(neighbors[i]) < 2]

added = set()
for h in head:

    curr = h
    if curr not in added:
        ans.append(curr)
        added.add(curr)
    while neighbors[curr]:
        nxt = neighbors[curr].pop()
        neighbors[nxt].remove(curr)
        curr = nxt
        if curr not in added:
            ans.append(curr)
            added.add(curr)

for i in ans:
    print(int_to_cow[i])