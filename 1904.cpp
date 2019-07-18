#include<iostream>
using namespace std;
int arr[1000000];
int res(int n){
  if(n==1)return 1;
  else if(n==2) return 2;
  else{
    for(int i=3;i<=n;i++){
      arr[i-1]=(arr[i-3] + arr[i-2])%15746;
    }
    return arr[n-1];
  }
}
int main(void){
  int N;
  cin>>N;
  arr[0]=1;
  arr[1]=2;
  cout<<res(N)<<endl;


  return 0;
}
