def calc(K,N):
    i=0
    P=2
    while i!=K:
        for j in range(1,1000):
            if P*j>N:
                break
            if che[P*j]!=-1:
                tmp=che[P*j]
                che[P*j]=-1
                i=i+1
                
            if i==K:
                return tmp
        while che[P]==-1:
            P=P+1
N,K=input().split()
N=int(N)
K=int(K)
che=list(range(0,N+1))
res=calc(K,N)
print(res)
