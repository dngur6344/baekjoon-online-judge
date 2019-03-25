F=list(range(9))
B=list(range(9))
U=list(range(9))
D=list(range(9))
L=list(range(9))
R=list(range(9))
in_put=list()
def init():
    tmp=list()
    for i in range(9):
        F[i]='r'
        B[i]='o'
        U[i]='w'
        D[i]='y'
        L[i]='g'
        R[i]='b'
def rotate(a,b,c,d,e,n):
    if n=='+':
        temp1=a[0]
        temp2=a[1]
        temp3=a[2]
        a[0]=b[6]
        a[1]=b[3]
        a[2]=b[0]
        b[0]=c[6]
        b[3]=c[7]
        b[6]=c[8]
        c[6]=d[8]
        c[7]=d[5]
        c[8]=d[2]
        d[2]=temp1
        d[5]=temp2
        d[8]=temp3
    elif n=='-':
        temp1=a[0]
        temp2=a[1]
        temp3=a[2]
        a[0]=d[2]
        a[1]=d[5]
        a[2]=d[8]
        d[2]=c[8]
        d[5]=c[7]
        d[8]=c[6]
        c[6]=b[0]
        c[7]=b[3]
        c[8]=b[6]
        b[0]=temp3
        b[3]=temp2
        b[6]=temp1
def rotate2(a,b,c,d,e,n):
    if n=='+':
        temp1=a[8]
        temp2=a[5]
        temp3=a[2]
        a[2]=b[2]
        a[5]=b[5]
        a[8]=b[8]
        b[2]=c[2]
        b[5]=c[5]
        b[8]=c[8]
        c[2]=d[6]
        c[5]=d[3]
        c[8]=d[0]
        d[6]=temp3
        d[3]=temp2
        d[0]=temp1
    elif n=='-':
        temp1=a[8]
        temp2=a[5]
        temp3=a[2]
        a[2]=d[6]
        a[5]=d[3]
        a[8]=d[0]
        d[0]=c[8]
        d[3]=c[5]
        d[6]=c[2]
        c[2]=b[2]
        c[5]=b[5]
        c[8]=b[8]
        b[2]=temp3
        b[5]=temp2
        b[8]=temp1
def self_rot(a,n):
    if n=='+':
        temp1=a[0]
        temp2=a[1]
        temp3=a[2]
        a[0]=a[6]
        a[1]=a[3]
        a[2]=temp1
        a[6]=a[8]
        a[3]=a[7]
        a[8]=temp3
        a[7]=a[5]
        a[5]=temp2
    elif n=='-':
        temp1=a[0]
        temp2=a[1]
        temp3=a[2]
        a[0]=a[2]
        a[1]=a[5]
        a[2]=a[8]
        a[5]=a[7]
        a[8]=a[6]
        a[6]=temp1
        a[7]=a[3]
        a[3]=temp2
n=int(input())
for i in range(n):
    n1=input()
    im=input().split()
    in_put.append(im)
while len(in_put)!=0:
    init()
    for i in in_put[0]:
        if i=='F+':
            rotate(D,R,U,L,F,'+')
            self_rot(F,'+')
        elif i=='F-':
            rotate(D,R,U,L,F,'-')
            self_rot(F, '-')
        elif i=='B+':
            rotate(U,L,D,R,B,'-')
            self_rot(B, '+')
        elif i=='B-':
            rotate(U,L,D,R,B,'+')
            self_rot(B, '-')
        elif i=='U+':
            for j in range(0,3):
                temp=F[j]
                F[j]=R[j]
                R[j]=B[j]
                B[j]=L[j]
                L[j]=temp
            self_rot(U, '+')
        elif i=='U-':
            for j in range(0,3):
                temp=F[j]
                F[j]=L[j]
                L[j]=B[j]
                B[j]=R[j]
                R[j]=temp
            self_rot(U, '-')
        elif i=='D+':
            for j in range(6,9):
                temp=F[j]
                F[j]=L[j]
                L[j]=B[j]
                B[j]=R[j]
                R[j]=temp
            self_rot(D, '+')
        elif i=='D-':
            for j in range(6,9):
                temp=F[j]
                F[j]=R[j]
                R[j]=B[j]
                B[j]=L[j]
                L[j]=temp
            self_rot(D, '-')
        elif i=='L+':
            temp1=U[0]
            temp2=U[3]
            temp3=U[6]
            U[0]=B[8]
            U[3]=B[5]
            U[6]=B[2]
            B[2]=D[6]
            B[5]=D[3]
            B[8]=D[0]
            D[0]=F[0]
            D[3]=F[3]
            D[6]=F[6]
            F[0]=temp1
            F[3]=temp2
            F[6]=temp3
            self_rot(L, '+')
        elif i=='L-':
            temp1=U[0]
            temp2=U[3]
            temp3=U[6]
            U[0]=F[0]
            U[3]=F[3]
            U[6]=F[6]
            F[0]=D[0]
            F[3]=D[3]
            F[6]=D[6]
            D[0]=B[8]
            D[3]=B[5]
            D[6]=B[2]
            B[8]=temp1
            B[5]=temp2
            B[2]=temp3
            self_rot(L, '-')
        elif i=='R+':
            rotate2(U,F,D,B,R,'+')
            self_rot(R, '+')
        elif i=='R-':
            rotate2(U,F,D,B,R,'-')
            self_rot(R, '-')
    in_put=in_put[1:len(in_put)]
    print(U[0]+""+U[1]+""+U[2])
    print(U[3]+""+U[4]+""+U[5])
    print(U[6]+""+U[7]+""+U[8])
