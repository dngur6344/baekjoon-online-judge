#include<iostream>
#include<string>
#include<deque>
using namespace std;
deque<string> app;
int maxim=0;
char visit[26];
void searching(int cnt,int i,int j,int r,int c){
  visit[app[i][j]-65]=1;
  if(i>0&&visit[app[i-1][j]-65]==0){
    searching(cnt+1,i-1,j,r,c);
  }
  if(i<r-1&&visit[app[i+1][j]-65]==0){
    searching(cnt+1,i+1,j,r,c);
  }
  if(j>0&&visit[app[i][j-1]-65]==0){
    searching(cnt+1,i,j-1,r,c);
  }
  if(j<c-1&&visit[app[i][j+1]-65]==0){
    searching(cnt+1,i,j+1,r,c);
  }
  if(cnt>maxim)maxim=cnt;
  visit[app[i][j]-65]=0;
  return;
}
int main(void){
  int r,c;
  string str;
  cin>>r>>c;
  for(int i=0;i<r;i++){
    cin>>str;
    app.push_back(str);
  }
  searching(1,0,0,r,c);
  cout<<maxim<<endl;

  return 0;
}
