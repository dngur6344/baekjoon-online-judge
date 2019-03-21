#include<iostream>
using namespace std;
int map[100][100];
int visit[100][100];
int mini=10000;
void filling(int cnt,int n,int i,int j){
  map[i][j]=cnt;
  if(i>0&&map[i-1][j]==1)
    filling(cnt,n,i-1,j);
  if(i<n-1&&map[i+1][j]==1)
    filling(cnt,n,i+1,j);
  if(j>0&&map[i][j-1]==1)
    filling(cnt,n,i,j-1);
  if(j<n-1&&map[i][j+1]==1)
    filling(cnt,n,i,j+1);
}
void counting(int N){
  int cnt=2;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(map[i][j]==1){
        filling(cnt,N,i,j);
        cnt++;
      }
    }
  }
}
void searching(int flag,int n,int i,int j,int cnt){
  if(cnt>=mini)return;
  if(map[i][j]!=0&&map[i][j]!=flag){
    mini=cnt;
    return;
  }
  visit[i][j]=1;
  if(i>0&&(map[i-1][j]==0||map[i-1][j]!=flag)&&visit[i-1][j]==0){
    searching(flag,n,i-1,j,cnt+1);
    visit[i-1][j]=0;
  }
  if(i<n-1&&(map[i+1][j]==0||map[i+1][j]!=flag)&&visit[i+1][j]==0){
    searching(flag,n,i+1,j,cnt+1);
    visit[i+1][j]=0;
  }
  if(j>0&&(map[i][j-1]==0||map[i][j-1]!=flag)&&visit[i][j-1]==0){
    searching(flag,n,i,j-1,cnt+1);
    visit[i][j-1]=0;
  }
  if(j<n-1&&(map[i][j+1]==0||map[i][j+1]!=flag)&&visit[i][j+1]==0){
    searching(flag,n,i,j+1,cnt+1);
    visit[i][j+1]=0;
  }
}
int main(void){
  int N;
  cin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cin>>map[i][j];
    }
  }
  counting(N);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(map[i][j]!=0){
        if(i>0&&map[i-1][j]==0)
          searching(map[i][j],N,i-1,j,1);
        if(i<N-1&&map[i+1][j]==0)
          searching(map[i][j],N,i+1,j,1);
        if(j>0&&map[i][j-1]==0)
          searching(map[i][j],N,i,j-1,1);
        if(j<N-1&&map[i][j-1]==0)
          searching(map[i][j],N,i,j+1,1);
      }
    }
  }
  cout<<mini-1<<endl;
  return 0;
}
