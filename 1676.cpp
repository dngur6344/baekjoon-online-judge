#include<iostream>
using namespace std;
int pactorial(int n){
    int cnt=0;
    int res=1;
    int tmp;
    while(n!=1){
        tmp=n;
        while(tmp%10==0){
            tmp=tmp/10;
            cnt+=1;
        }
        res*=tmp;
        n--;
        while(res%10==0){
            res=res/10;
            cnt+=1;
        }
        if(res>100000){
            res=res%100000;
        }
    }
    return cnt;
}
int main(void){
    int N,res;
    cin>>N;
    if(N==0){
        cout<<0<<endl;
        return 0;
    }
    res=pactorial(N);
    cout<<res<<endl;
    return 0;
}
