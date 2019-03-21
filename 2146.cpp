#include<iostream>
#include<deque>
using namespace std;
int map[100][100];
int visit[100][100];
int mini=10000;
class two{
private:
public:
  int i;
  int j;
};
deque<two> dq;
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
void initiate(int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      visit[i][j]=0;
    }
  }
}
int main(void){
  int N;
  two inp;
  int cnt=1;
  int tmp;
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
        inp.i=i;
        inp.j=j;
        cnt=1;
        visit[i][j]=1;
        initiate(N);
        dq.push_back(inp);
        while(dq.empty()!=true){
          tmp=dq.size();
          for(int k=0;k<tmp;k++){
            if(map[dq[0].i][dq[0].j]!=0&&map[dq[0].i][dq[0].j]!=map[i][j]){
              dq.clear();
              if(cnt<mini)mini=cnt;
              break;
            }
            if(dq[0].i>0&&(map[dq[0].i-1][dq[0].j]==0||map[dq[0].i-1][dq[0].j]!=map[i][j])&&visit[dq[0].i-1][dq[0].j]==0){
              inp.i=dq[0].i-1;
              inp.j=dq[0].j;
              dq.push_back(inp);
              visit[dq[0].i-1][dq[0].j]=1;
            }
            if(dq[0].i<N-1&&(map[dq[0].i+1][dq[0].j]==0||map[dq[0].i+1][dq[0].j]!=map[i][j])&&visit[dq[0].i+1][dq[0].j]==0){
              inp.i=dq[0].i+1;
              inp.j=dq[0].j;
              dq.push_back(inp);
              visit[dq[0].i+1][dq[0].j]=1;
            }
            if(dq[0].j>0&&(map[dq[0].i][dq[0].j-1]==0||map[dq[0].i][dq[0].j-1]!=map[i][j])&&visit[dq[0].i][dq[0].j-1]==0){
              inp.i=dq[0].i;
              inp.j=dq[0].j-1;
              dq.push_back(inp);
              visit[dq[0].i][dq[0].j-1]=1;
            }
            if(dq[0].j<N-1&&(map[dq[0].i][dq[0].j+1]==0||map[dq[0].i][dq[0].j+1]!=map[i][j])&&visit[dq[0].i][dq[0].j+1]==0){
              inp.i=dq[0].i;
              inp.j=dq[0].j+1;
              dq.push_back(inp);
              visit[dq[0].i][dq[0].j+1]=1;
            }
            dq.pop_front();
          }
          cnt++;
        }
      }
    }
  }
  cout<<mini-2<<endl;
  return 0;
}
