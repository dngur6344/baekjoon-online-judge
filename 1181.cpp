#include<iostream>
#include<deque>
#include<string>
using namespace std;
deque<string> dq;
void dictionary(int n,int m){
  string tmp;
  int i;
  for(i=0;i<dq[n].size()&&i<dq[m].size();i++){
    if(dq[n][i]>dq[m][i]){
      tmp=dq[n];
      dq[n]=dq[m];
      dq[m]=tmp;
      return;
    }
    else if(dq[n][i]==dq[m][i])continue;
    else return;
  }
  if(i==dq[m].size()){
    tmp=dq[n];
    dq[n]=dq[m];
    dq[m]=tmp;
  }
}
void sorting(){
  string tmp;
  deque<string> :: iterator am;
  for(int i=0;i<dq.size()-1;i++){
    for(int j=i+1;j<dq.size();j++){
      if(dq[i].size()>dq[j].size()){
        tmp=dq[i];
        dq[i]=dq[j];
        dq[j]=tmp;
      }
      else if(dq[i].size()==dq[j].size()){
        if(dq[i]==dq[j]){
          for(am=dq.begin();*am!=dq[j];am++){}
          dq.erase(am);
        }
        else dictionary(i,j);
      }
    }
  }
}
int main(void){
  int num;
  string st;
  cin>>num;
  for(int i=0;i<num;i++){
    cin>>st;
    dq.push_back(st);
  }
  sorting();
  for(int i=0;i<dq.size();i++)
    cout<<dq[i]<<endl;
  return 0;
}
