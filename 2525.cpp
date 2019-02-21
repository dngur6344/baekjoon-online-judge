#include<iostream>
using namespace std;
int main(void){
    int A,B,C;
    int tmp=0;
    cin>>A>>B;
    cin>>C;
    if(B+C>=60){
        tmp=(B+C)/60;
        B=(B+C)%60;
    }
    else B=B+C;
    A=A+tmp;
    if(A>=24)
        A=A-24;
    cout<<A<<" "<<B<<endl;
    return 0;
}
