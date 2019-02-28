a=input()
li=list(a)
flag=1
if len(li)%2==0:
    for i in range(int(len(li)/2)):
        if li[i]!=li[len(li)-1-i]:
            flag=0
            break
    print(flag)
elif len(li)%2==1:
    for i in range(int((len(li)-1)/2)):
        if li[i]!=li[len(li)-1-i]:
            flag=0
            break
    print(flag)
