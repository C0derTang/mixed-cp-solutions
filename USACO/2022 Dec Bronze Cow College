import io, os, sys, collections

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

n = int(input())
cows = [int(i) for i in input().split()]

cows.sort()
max_price = max_tut = 0
for i, cow in enumerate(cows):
    price = cow * (n-i)
    if price > max_price:
        max_price = price
        max_tut = cow
print(max_price, max_tut)
