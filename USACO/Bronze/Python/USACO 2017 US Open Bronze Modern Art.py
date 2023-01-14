import sys

sys.stdin = open('art.in', 'r')
sys.stdout = open('art.out', 'w')

input = sys.stdin.readline

n=int(input())
grid=[[int(i) for i in input().strip()] for _ in range(n)]

rect=[]
for clr in range(10):
	rect.append([n,n,-1,-1])

for i in range(n):
	for j in range(n):
		a=grid[i][j]
		if a>0:
			rect[a][0]=min(rect[a][0],i)
			rect[a][1]=min(rect[a][1],j)
			rect[a][2]=max(rect[a][2],i)
			rect[a][3]=max(rect[a][3],j)

ans=0
not_original=[0]*10
for clr in range(10):
	if rect[clr][0]<n:
		ans=ans+1
		for i in range(rect[clr][0], rect[clr][2]+1):
			for j in range(rect[clr][1], rect[clr][3]+1):
				if grid[i][j]!=clr:
					not_original[grid[i][j]]=1

print(rect)
print(ans-sum(not_original))