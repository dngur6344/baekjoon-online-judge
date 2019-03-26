#include<stdio.h>
#include<deque>
#include<stdlib.h>
using namespace std;
int dq[100000][2];
int compare(const void *a, const void *b){
  int num1=*(int*)a;
  int num2=*(int*)b;

  if(num1>num2)
    return 1;
  else if(num1==num2){
    if(*((int*)a+1)>*((int*)b+1))
    return 1;
  }
  return -1;
}
int main(void){
  int num;
  scanf("%d",&num);
  for(int i=0;i<num;i++){
    scanf("%d %d",&dq[i][0],&dq[i][1]);
  }
  int idx;
  int tmp1,tmp2;
  qsort(dq,num,sizeof(dq[0]),compare);
  for(int i=0;i<num;i++){
    printf("%d %d\n",dq[i][0],dq[i][1]);
  }
  return 0;
}
