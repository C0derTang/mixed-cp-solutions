'''
PROBLEM STATEMENT:
http://www.usaco.org/index.php?page=viewproblem2&cpid=809

LOGIC:
(the explanation, not the rapper)
If we know a day came after a break, lets call the value in the array d.
The previous d-1 days must have the values [d-1,d-2...0],
because each earlier day means that day is one less day after a break.

We iterate over the array in reverse, finding all the known days.
The minimum of breaks must be the known values of 0,
and the maximum is the number of zeros and the number of -1s,
since each remaining -1 can potentially be a 0.
'''

#import sys package to help with file I/O
import sys

#set standard I/O to files
sys.stdin = open('taming.in', 'r')
sys.stdout = open('taming.out', 'w')

#faster input
input = sys.stdin.readline

#read in input
n = int(input())
days = [int(i) for i in input().split()]
#first day must be a breakout, so it is guaranteed no matter what the value is 0
days[0] = 0

#boolean keeps track of whether or not there is a valid solution
val = True
#calculate breakouts in reverse
for i in range(n-1, 0, -1):
    #if we know days[i] is after a break,
    #we update the day before that to days[i]-1 after a break.
    #if there is a value besides days[i]-1 or -1, we know the array is inconsistend
    if days[i] > 0:
        if days[i-1] != days[i]-1 and days[i-1] != -1:
            #break the loop, no more calcuation is needed
            val = False
            break
        else:
            #otherwise update the array
            days[i-1] = days[i] - 1

#print answer only if array is consistent, else print -1
#we filled in all known values in the for loop,
#we know for sure the zeros are breaks,
#but the remaining -1s all have potential to be a break
if val:
    print(days.count(0), days.count(0) + days.count(-1))
else:
    print(-1)
