import sys
sys.setrecursionlimit(10**6)
visiting=list()
num=int(input())
arr=list()
maximum=0
result=0
def initiate(num):
    for i in range(num):
        visiting.append([])
    for i in visiting:
        for j in range(num):
            i.append(0)
def fix_zero(num):
    for i in range(num):
        for j in range(num):
            visiting[i][j]=0
def finding(i,j,num,height):
    visiting[i][j]=1
    if i>0 and visiting[i-1][j]==0 and arr[i-1][j]>=height:
        finding(i-1,j,num,height)
    if i+1<num and visiting[i+1][j]==0 and arr[i+1][j]>=height:
        finding(i+1,j,num,height)
    if j>0 and visiting[i][j-1]==0 and arr[i][j-1]>=height:
        finding(i,j-1,num,height)
    if j+1<num and visiting[i][j+1]==0 and arr[i][j+1]>=height:
        finding(i,j+1,num,height)
for i in range(num):
    im=input().split()
    for j in range(len(im)):
        im[j]=int(im[j])
    arr.append(im)
for i in range(num):
    for j in arr[i]:
        if j>maximum:
            maximum=j
initiate(num)
cnt=0
for i in range(1,maximum+1):
    for j in range(num):
        for k in range(num):
            if visiting[j][k]==0 and arr[j][k]>=i:
                finding(j,k,num,i)
                cnt=cnt+1
    if cnt>result:
        result=cnt
    cnt=0
    fix_zero(num)
print(result)
