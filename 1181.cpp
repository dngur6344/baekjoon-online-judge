#include<iostream>
#include<deque>
#include<string>
#include<algorithm>
using namespace std;
deque<string> dq;
bool compare(string a,string b){
  if(a.size()>b.size())
    return false;
  else if(a.size()<b.size())
    return true;
  else if(a.size()==b.size()){
    return a<b;
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
  sort(dq.begin(),dq.end(),compare);
  for(int i=0;i<dq.size();i++){
    if(i!=0&&dq[i]==dq[i-1])continue;
    cout<<dq[i]<<endl;
  }
  return 0;
}
