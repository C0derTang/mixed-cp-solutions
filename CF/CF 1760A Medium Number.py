import sys
input = sys.stdin.readline

for _ in range(int(input())):
    nums = [int(i) for i in input().split()]
    nums.sort()
    print(nums[1])
