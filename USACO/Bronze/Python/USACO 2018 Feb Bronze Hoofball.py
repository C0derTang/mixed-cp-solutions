'''
LOGIC:
We can find the number of balls needed by identifying the cows that no one passes to.
These cows are the ones that MUST start with a ball.
We calculate where the ball goes from a certain index, and store it in an array.

EDGE CASE:
Two adjacent cows pass back and forth.
'''

#import sys package to help with file I/O
import sys

#set standard I/O to files
sys.stdin = open('hoofball.in', 'r')
sys.stdout = open('hoofball.out', 'w')

#faster input
input = sys.stdin.readline

#read in input
n = int(input())
cows = [int(i) for i in input().split()]

#array to keep track of how many possible balls get passed to which cow
pass_to = [0] * n

#function finds where ball goes next from the given index
def target(i):
    #initialize the index of left and right neighbors
    lnb = rnb = -1
    #initialize the distance between i and lnb and rnb
    ldist = rdist = 1000
    #minimize ldist and find closest lnb
    for j in range(n):
        if cows[j] < cows[i] and cows[i]-cows[j] < ldist:
            lnb = j
            ldist = cows[i] - cows[j]
    #minimize rdist and find closest rnb
    for j in range(n):
        if cows[j] > cows[i] and cows[j]-cows[i] < rdist:
            rnb = j
            rdist = cows[j] - cows[i]
    #return closest neighbor
    if ldist <= rdist:
        return lnb
    return rnb

#calculate where passes end up for every target and store in pass_to
for i in range(n):
    pass_to[target(i)] += 1


ans = 0
for i in range(n):
    #if no balls are passed to this cow,
    #that means this cow must start with a ball to get it at least once
    if pass_to[i] == 0:
        ans += 1
    #edge case where two cows pass only back and forth, needing one ball.
    #checks the index to make sure no duplicate,
    #and if the pass of the pass ends up to the original passer
    if i < target(i) and target(target(i)) == i and pass_to[i] == 1 and pass_to[target(i)] == 1:
        ans += 1

#writes answer to file
print(ans)
