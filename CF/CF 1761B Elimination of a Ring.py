import sys, io, os, collections

#input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
input = sys.stdin.readline

def solve():
    n = int(input())
    a = [int(i) for i in input().split()]

    if n <= 3:
        return n

    if len(set(a)) == 2:
        ans = 0
        i = 0
        while a:
            ans += 1
            a.pop(i)
            #print(a, i, ans)
            if a[i] == a[i-1]:
                a.pop(i-1)
                #print(a, i, ans)
            if len(a) <= 3:
                return ans + len(a)
        return ans
    return n  
    '''
    ans = i = 0
    while i < len(a):
        if len(a) <= 3:
            return ans + len(a)
        if a[i-1] != a[(i+1)% len(a)]:
            ans += 1
            a.pop(i)
            #i-=1
        else:
            i += 1
        print(a, i, ans)
    if len(a) <= 3:
            return ans + len(a)
    print()
    i = 0
    while a:
        ans += 1
        a.pop(i)
        print(a, i, ans)
        if a[i] == a[i-1]:
            a.pop(i-1)
            print(a, i, ans)
        if len(a) <= 3:
            return ans + len(a)
    return ans
    '''

for _ in range(int(input())):
    sys.stdout.write(str(solve()) + '\n')


