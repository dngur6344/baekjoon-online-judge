input_str=list()
past=list()
def searching(cnt,i,j,r,c,maxim):
    past.append(input_str[i][j])
    if i>0 and past.count(input_str[i-1][j])==0:
        maxim=searching(cnt+1,i-1,j,r,c,maxim)
    if i<r-1 and past.count(input_str[i+1][j])==0:
        maxim=searching(cnt+1,i+1,j,r,c,maxim)
    if j>0 and past.count(input_str[i][j-1])==0:
        maxim=searching(cnt+1,i,j-1,r,c,maxim)
    if j<c-1 and past.count(input_str[i][j+1])==0:
        maxim=searching(cnt+1,i,j+1,r,c,maxim)
    past.pop()
    if maxim<cnt:
        maxim=cnt
    return maxim
r,c=input().split()
r=int(r)
c=int(c)
maxim=0
for i in range(r):
    tmp=input()
    input_str.append(tmp)
maxim=searching(1,0,0,r,c,maxim)
print(maxim)
