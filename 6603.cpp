#include<iostream>
#include<stdlib.h>
using namespace std;
int res[100];
int su[100];
void DFS(int num1,int num2,int k){
    if(num2==6){
        for(int i=0;i<6;i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return;
    }
    else{
        for(int i=num1;i<k;i++){
            res[num2]=su[i];
            DFS(i+1,num2+1,k);
        }
    }
}
int main(void){
    int k;
    cin>>k;
    while(k!=0){
        for(int i=0;i<k;i++){
            cin>>su[i];
        }
        DFS(0,0,k);
        cout<<endl;
        cin>>k;
    }
    return 0;
}
