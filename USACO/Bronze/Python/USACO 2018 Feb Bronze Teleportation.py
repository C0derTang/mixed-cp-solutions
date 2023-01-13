'''
PROBLEM STATEMENT:
http://www.usaco.org/index.php?page=viewproblem2&cpid=807

LOGIC:
(Eminem is better)
Since there are only two points and two teleporters,
there are a two possiblilities.
The sum of the minimum distances between a to a teleporter and b to a teleporter,
and the distance between the location a and the location b
'''

#import sys package to help with file I/O
import sys

#set standard I/O to files
sys.stdin = open('teleport.in', 'r')
sys.stdout = open('teleport.out', 'w')

#faster input
input = sys.stdin.readline

#read in input
a, b, x, y  = map(int, input().split())

#"min(abs(a-x), abs(a-y)" finds the closest distance from a to a teleporter
#"min(abs(b-x), abs(b-y)" finds the closest distance from b to a teleporter
#we add "min(abs(a-x), abs(a-y))" and "min(abs(b-x), abs(b-y)" to find the
#the total walking distance while optimally using the teleporters.
#We compare that to the distance of just walking and take the minimum
print(min(min(abs(a-x), abs(a-y)) + min(abs(b-x), abs(b-y)), abs(a-b)))
