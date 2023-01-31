import sys

input = sys.stdin.readline

n = int(input())
a = [int(i) for i in input().split()]

freq = [0]*n
freq[0] = 1

ans = cur = 0
for num in a:
    cur = (cur+num)%n
    ans += freq[cur]
    freq[cur] += 1
print(ans)