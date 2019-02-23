#include<iostream>
#include<queue>
using namespace std;
int mini=-1;
queue<int> q;
void searching(int a,int b,int cnt){
    q.push(a);
    int flag=0;
    int tmp=1;
    while(1){
        for(int i=0;i<tmp;i++){
            /*if(a-1>=0){
             q.push(a-1);
             }*/
            if(q.front()==b){
                flag=1;
                break;
            }
            q.push(q.front()-1);
            q.push(q.front()+1);
            q.push(2*q.front());
            q.pop();
        }
        if(flag==1)
            break;
        cnt++;
        tmp=1;
        for(int i=0;i<cnt;i++){
            tmp=tmp*3;
        }
    }
    mini=cnt;
}
int main(void){
    int N,K;
    cin>>N>>K;
    searching(N,K,0);
    cout<<mini<<endl;
    return 0;
}
