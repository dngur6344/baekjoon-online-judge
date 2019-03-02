def init(a):
    for i in range(len(a)):
        a[i]=0
def init_lin(b,c):
    for i in range(c):
        b.append([])
def DFS(linked,visit,i):
    visit[i]=1
    for j in linked[i]:
        if visit[j]==0:
            DFS(linked,visit,j)
N,M=input().split()
N=int(N)
M=int(M)
linked=list()
visit=list(range(N))
init_lin(linked,N)
init(visit)
for i in range(M):
    num1,num2=input().split()
    num1=int(num1)
    num2=int(num2)
    linked[num1-1].append(num2-1)
count=0
for i in range(N):
    if visit[i]==0:
        DFS(linked,visit,i)
        count+=1
print(count)
