#include<iostream>
using namespace std;
int minim(int a,int b,int c){
	if(c==-1){
		if(a>b)return b;
		else return a;
	}
	else{
		if(a>b){
			if(b>c)return c;
			else return b;
		}
		else{
			if(a>c)return c;
			else return a;
		}
	}
}
int main(void){
	int n1,n2,n3,c1,c2;
	int res;
	int mini;
	cin>>n1;
	cin>>n2;
	cin>>n3;
	cin>>c1;
	cin>>c2;
	mini=minim(n1,n2,n3);
	mini+=minim(c1,c2,-1);
	cout<<mini-50<<endl;
	return 0;
}
