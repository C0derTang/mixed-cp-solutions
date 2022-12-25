import io, os, sys, collections

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
    n = int(input())
    a = [int(i) for i in input().split()]

    for target in range(max(a), sum(a)+1):
        test_a = collections.deque(a)
        count = 0
        val = True
        moves = 0
        while test_a:
            count += test_a.popleft()
            if count > target:
                val = False
                break
            elif count == target:
                count = 0
            else:
                moves += 1
        if val: return moves
    return n-1


for _ in range(int(input())):
    sys.stdout.write(str(solve()) + '\n')
