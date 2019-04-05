n=input()
m=int(n)
flag=0
for i in range(1,m+1):
    tmp=i
    st=str(tmp)
    for j in st:
        tmp=tmp+int(j)
    if tmp==m:
        flag=1
        print(i)
        break
if flag==0:
    print(0)
