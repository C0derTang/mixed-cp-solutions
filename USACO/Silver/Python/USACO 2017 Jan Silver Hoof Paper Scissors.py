import sys

sys.stdin = open('hps.in', 'r')
sys.stdout = open('hps.out', 'w')

input = sys.stdin.readline

n = int(input())
moves = [input().strip() for _ in range(n)]

p_h, p_p, p_s = [0] * (n+1), [0] * (n+1), [0] * (n+1)
for i in range(n):
    p_h[i+1] = p_h[i]
    p_p[i+1] = p_p[i]
    p_s[i+1] = p_s[i]
    if moves[i] == 'H':
        p_p[i+1] += 1
    elif moves[i] == 'P':
        p_s[i+1] += 1
    else:
        p_h[i+1] += 1

ans = max(p_h[-1], p_p[-1], p_s[-1])
for switch in range(n+1):
    h_to_p = p_h[switch] + (p_p[-1] - p_p[switch])
    p_to_h = p_p[switch] + (p_h[-1] - p_h[switch])
    p_to_s = p_p[switch] + (p_s[-1] - p_s[switch])
    s_to_p = p_s[switch] + (p_p[-1] - p_p[switch])
    s_to_h = p_s[switch] + (p_h[-1] - p_h[switch])
    h_to_s = p_h[switch] + (p_s[-1] - p_s[switch])

    ans = max(ans, h_to_p, p_to_h, p_to_s, s_to_p, s_to_h, h_to_s)
print(ans)