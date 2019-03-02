#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;
int visit[1000]={0,};
list<int> linked[1000];
void DFS(int n,int i){
    visit[i]=1;
    list<int>::iterator arrow=linked[i].begin();
    for(int j=0;j<linked[i].size();j++){
        if(visit[*arrow]==0)
            DFS(n,*arrow);
        arrow++;
    }
}
int main(void){
    int N,M;
    int num1,num2,cnt=0;
    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>num1>>num2;
        linked[num1-1].push_back(num2-1);
        linked[num2-1].push_back(num1-1);
    }
    for(int i=0;i<N;i++){
        if(visit[i]==0){
            DFS(N,i);
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
