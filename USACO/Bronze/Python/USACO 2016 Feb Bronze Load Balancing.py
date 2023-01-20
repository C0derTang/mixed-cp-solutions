import sys

sys.stdin = open('balancing.in', 'r')
sys.stdout = open('balancing.out', 'w')

input = sys.stdin.readline

n, b = map(int, input().split())

xs = [0]*n
ys = [0]*n

v_fence = set()
h_fence = set()

for i in range(n):
   xs[i], ys[i] = map(int, input().split())
   v_fence.add(xs[i]+1)
   h_fence.add(ys[i]+1)

ans = n
for v in v_fence:
   for h in h_fence:
      tl = tr = bl = br = 0
      for i in range(n):
         if xs[i] > v:
            if ys[i] > h:
               tr += 1
            else:
               tl += 1
         else:
            if ys[i] > h:
               br += 1
            else:
               bl += 1
      ans = min(ans, max(tl, tr, bl, br))

print(ans)