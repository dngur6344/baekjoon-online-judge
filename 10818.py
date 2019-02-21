N=int(input())
a=input().split()
for i in range(N):
    a[i]=int(a[i])
a.sort()
print(a[0],a[len(a)-1])
