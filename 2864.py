def invert(n,a):
    n1=a.count(n)
    for i in range(n1):
        n1_1=a.index(n)
        if n=='5':
            a[n1_1]='6'
        elif n=='6':
            a[n1_1]='5'

num1,num2=input().split()
a=list(num1)
b=list(num2)

invert('5',a)
invert('5',b)
z1=""
z2=""
for i in range(len(a)):
    z1=z1+str(a[i])
for i in range(len(b)):
    z2=z2+str(b[i])
z1=int(z1)
z2=int(z2)
maxim=z1+z2

invert('6',a)
invert('6',b)
z1=""
z2=""
for i in range(len(a)):
    z1=z1+str(a[i])
for i in range(len(b)):
    z2=z2+str(b[i])
z1=int(z1)
z2=int(z2)
mini=z1+z2
print(mini,maxim)
