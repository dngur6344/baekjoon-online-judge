d=list()
b=list()
n1,n2=input().split()
n1=int(n1)
n2=int(n2)
for i in range(n1):
    tmp=input()
    d.append(tmp)
d1=set(d)
for i in range(n2):
    tmp=input()
    b.append(tmp)
b1=set(b)
db1=d1&b1
db=list(db1)
db.sort()
print(len(db))
db.sort()
for i in db:
    print(i)
