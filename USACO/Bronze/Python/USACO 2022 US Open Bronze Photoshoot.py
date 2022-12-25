n = int(input())
s = input().strip()

'''
simulate flips by maintaining the last group to flip together, 
since the same flip can flip all of the pairs that are in the same direction. 
H pairs do not count, and can be flipped back and forth. 
reverse flips with h at the end
if h is last, no need to flip bc it is already in place.
'''
flip = '.'
ans = 0
for i in range(0, n, 2):
    if s[i] != s[i+1]:
        if s[i] != flip:
            ans += 1
            flip = s[i]
if flip == 'H':
    ans -= 1

print(ans)