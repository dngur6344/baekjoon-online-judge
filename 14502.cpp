#include<iostream>
#include<deque>
using namespace std;
class two{
private:

  public :
  int row;
  int col;
};
int arr[8][8];
int tmp[8][8];
int max_val=0;
int cnt=0;
deque<two> dq;
deque<two> virus;
void init(int a,int b){
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      tmp[i][j]=arr[i][j];
    }
  }
}
void deque_stack(int a,int b){
  two am;
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      if(arr[i][j]==0){
        am.row=i;
        am.col=j;
        dq.push_back(am);
      }
      else if(arr[i][j]==2){
        am.row=i;
        am.col=j;
        virus.push_back(am);
      }
    }
  }
}
void DFS_func(int row,int col,int a,int b){
  cnt++;
  if(row>0&&tmp[row-1][col]==0){
    tmp[row-1][col]=2;
    DFS_func(row-1,col,a,b);
  }
  if(row<a-1&&tmp[row+1][col]==0){
    tmp[row+1][col]=2;
    DFS_func(row+1,col,a,b);
  }
  if(col>0&&tmp[row][col-1]==0){
    tmp[row][col-1]=2;
    DFS_func(row,col-1,a,b);
  }
  if(col<b-1&&tmp[row][col+1]==0){
    tmp[row][col+1]=2;
    DFS_func(row,col+1,a,b);
  }
}
int main(void){
  int N,M;
  int temper;
  cin>>N>>M;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>arr[i][j];
    }
  }
  deque_stack(N,M);
  init(N,M);
  temper=N*M-dq.size()-virus.size();
  for(int fir=0;fir<dq.size()-2;fir++){
    for(int sec=fir+1;sec<dq.size()-1;sec++){
      for(int thr=sec+1;thr<dq.size();thr++){
        tmp[dq[fir].row][dq[fir].col]=1;
        tmp[dq[sec].row][dq[sec].col]=1;
        tmp[dq[thr].row][dq[thr].col]=1;
        cnt=0;
        for(int i=0;i<virus.size();i++){
          DFS_func(virus[i].row,virus[i].col,N,M);
        }
        cnt=N*M-cnt;
        cnt=cnt-(temper+3);
        if(cnt>max_val)max_val=cnt;
        init(N,M);
      }
    }
  }
  cout<<max_val<<endl;
  return 0;
}
