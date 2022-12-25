import sys

sys.stdin = open('teleport.in', 'r')
sys.stdout = open('teleport.out', 'w')

input = sys.stdin.readline

a, b, x, y  = map(int, input().split())

print(min(min(abs(a-x), abs(a-y)) + min(abs(b-x), abs(b-y)), abs(a-b)))