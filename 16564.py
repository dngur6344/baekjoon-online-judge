x=list()
N,K=input().split()
N=int(N)
K=int(K)
for i in range(N):
    a=int(input())
    x.append(a)
x.sort()
i=0
j=0
cnt=1
while True:
    if i==N-1 and K<N:
        break
    elif i==N-1 and K>=N:
        '''while K>=N:
            for j in range(N):
                x[j]=x[j]+1
            K=K-N'''
        while cnt*N<=K:
            cnt+=1
        x[0]+=cnt-1
        K=K-N*cnt
        break
    else:
        tmp=x[i+1]-x[i]
        if (i+1)*tmp>K:
            '''while i+1<K:
                for j in range(i+1):
                    x[j]=x[j]+1
                K-=(i+1)'''
            while cnt*(i+1)<=K:
                cnt+=1
            x[0]+=cnt-1
            break
        x[0]+=tmp
        K=K-tmp*(i+1)
        i=i+1

print(x[0])
