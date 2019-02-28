li=list()
am=input()
for i in range(len(am)):
    tmp=am
    li.append(tmp[i:])
li.sort()
for i in li:
    print(i)
