import sys

input = sys.stdin.readline

def solve():
    n = int(input())
    hunger = [int(i) for i in input().split()]
    ans = 0
    while True:
        #check every hunger to make sure its valid
        for a in hunger:
            if a < 0:
                print(-1)
                return
        #check if all hunger level is the same
        if hunger.count(hunger[0]) == len(hunger):
            print(ans)
            return
        #find the smallest value, and try to match it throughout
        smallest = min(hunger)
        for i in range(len(hunger)-1):
            if hunger[i] > smallest:
                dif = hunger[i] - smallest
                hunger[i] -= dif 
                hunger[i+1] -= dif
                ans += 2 * dif
        #if the second to last value is greater than the last, there is no way to fix, therefore invalid
        if hunger[-1] > hunger[-2]:
            print(-1)
            return

for _ in range(int(input())):
    solve()