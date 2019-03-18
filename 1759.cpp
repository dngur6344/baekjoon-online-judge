#include<iostream>
#include<deque>
#include<string>
#include<stdlib.h>
using namespace std;
deque<char> dq;
deque<char> res;
int *visit;
void sorting(){
    char tmp;
    for(int i=0;i<dq.size()-1;i++){
        for(int j=i+1;j<dq.size();j++){
            if(dq[i]>dq[j]){
                tmp=dq[i];
                dq[i]=dq[j];
                dq[j]=tmp;
            }
        }
    }
}
void init(int N){
    for(int i=0;i<N;i++)
        visit[i]=0;
}
int checking(int n){
  int cnt1=0,cnt2=0;
  for(int i=0;i<n;i++){
    if(res[i]=='a'||res[i]=='e'||res[i]=='i'||res[i]=='o'||res[i]=='u')
      cnt1++;
     else cnt2++;
  }
  if(cnt1>=1&&cnt2>=2)return 1;
  else return 0;
}
void visiting(int n,int longer,int current){
  if(res.size()==n){
    if(checking(n)==1){
      for(int i=0;i<n;i++){
        cout<<res[i];
      }
      cout<<endl;
    }
    return;
  }
  for(int i=current;i<longer;i++){
    if(visit[i]==0){
      visit[i]=1;
      res.push_back(dq[i]);
      visiting(n,longer,i+1);
      res.pop_back();
      visit[i]=0;
    }
  }
}
int main(void){
    int L,C;
    char tmp;
    cin>>L>>C;
    for(int i=0;i<C;i++){
        cin>>tmp;
        dq.push_back(tmp);
    }
    visit=(int*)malloc(sizeof(int)*(dq.size()));
    sorting();
    init(dq.size());
    visiting(L,C,0);
    return 0;
}
