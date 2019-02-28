import sys
sys.setrecursionlimit(100000)
a=list()
visit=list()
def checking(num):
    count=0
    for i in range(num):
        for j in range(num):
            if visit[i][j]==0:
                DFS(a[i][j],i,j,num)
                count+=1
    return count
def DFS(ch,i,j,num):
    visit[i][j]=1
    if i-1>=0 and visit[i-1][j]==0 and ch==a[i-1][j]:
        DFS(ch,i-1,j,num)
    if i+1<num and visit[i+1][j]==0 and ch==a[i+1][j]:
        DFS(ch,i+1,j,num)
    if j-1>=0 and visit[i][j-1]==0 and ch==a[i][j-1]:
        DFS(ch,i,j-1,num)
    if j+1<num and visit[i][j+1]==0 and ch==a[i][j+1]:
        DFS(ch,i,j+1,num)
def init_RG(num):
    for i in range(num):
        for j in range(num):
            if a[i][j]=='G':
                a[i][j]='R'
def init(num):
    for i in range(num):
        for j in range(num):
            visit[i][j]=0
num=int(input())
for i in range(num):
    tmp=input()
    a.append(list(tmp))
    visit.append(list(range(num)))
init(num)
cnt1=checking(num)
init_RG(num)
init(num)
cnt2=checking(num)
print(cnt1,cnt2)
