
num=int(input())
a=input().split()
for i in range(len(a)):
    a[i]=int(a[i])
tmp=len(a)-2
b=""
for i in a:
    b=b+str(i)
c=int(b)
b_1=""
bi=a[tmp]
a[tmp]=a[tmp+1]
a[tmp+1]=bi
for i in a:
    b_1=b_1+str(i)
c_1=int(b_1)
if c_1>c:
    for i in range(len(b_1)):
        print(b_1[i],end=" ")
else:
    j=3
    while True:
        if len(a)-j<0:
            print(-1)
            break
        tmp=a[len(a)-j]
        minim=10002
        for i in range(len(a)-j,num):
            if a[i]>tmp and a[i]<minim:
                minim=a[i]
                minim_idx=i
        if minim==10002:
            j=j+1
            continue
        else:
            bi=a[len(a)-j]
            a[len(a)-j]=a[minim_idx]
            a[minim_idx]=bi
            res=""
            for i in range(len(a)-j+1,num):
                res=res+str(a[i])
            resu=list(res)
            for i in range(len(resu)):
                resu[i]=int(resu[i])
            resu.sort()
            for i in range(len(a)-j+1,num):
                a[i]=resu[i-len(a)+j-1]
            for i in a:
                print(str(i),end=" ")
            break
            

