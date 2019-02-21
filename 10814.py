arr=list()
for i in range(201):
    arr.append([])
N=int(input())
for i in range(N):
    age,name=input().split()
    age=int(age)
    arr[age].append(name)
for i in range(len(arr)):
    if len(arr[i])!=0:
        for j in arr[i]:
            print(i,j)
