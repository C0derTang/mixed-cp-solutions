import sys

sys.stdin = open('highcard.in', 'r')
sys.stdout = open('highcard.out', 'w')

input = sys.stdin.readline

n = int(input())
e = set(int(input()) for _ in range(n))
e_s, b_s = [], []
for i in range(1, 2*n+1):
	if i in e:
		e_s.append(i)
	else:
		b_s.append(i)

ep = bp = ans = 0
while ep < n and bp < n:
	if b_s[bp] > e_s[ep]:
		ep += 1
		ans += 1
	bp += 1

print(ans)