import sys

input = sys.stdin.readline

n = int(input())

odds = evens = 0
for i in input().split():
    if int(i)%2:
        odds += 1
    else:
        evens += 1

ans = 0
even = True
while evens or odds:
    if even and evens:
        evens -= 1
    elif not even and odds:
        odds -= 1
    else:
        break
    ans += 1
    even = not even
#print(ans)

even = True
while odds:
    if even:
        odds -= 2
        ans += 1
    else:
        if not odds % 2:
            odds = 0
            #ans += 1
            break
        else:
            odds -= 1
            ans += 1
    even = not even
            
print(ans)
