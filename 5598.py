a=input()
b=list(a)
c=list()
for i in b:
    if ord(i)-3<ord('A'):
        tmp=ord(i)-ord('A')
        res=ord('Z')+1-3+tmp
    else:
        res=ord(i)-3
    c.append(chr(res))
result=""
for i in c:
    result+=i
print(result)
