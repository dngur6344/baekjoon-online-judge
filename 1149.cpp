#include<iostream>
#include<deque>
using namespace std;
class color{
private:
public:
	int r;
	int g;
	int b;
};
deque<color> dq;
int mini(int a,int b){
	if(a>b)
		return b;
	else
		return a;
}
int main(void){
	int N;
	cin>>N;
	color cl;
	for(int i=0;i<N;i++){
		cin>>cl.r>>cl.g>>cl.b;
		dq.push_back(cl);
	}
	deque<color> dq2(N);
	dq2[0].r=dq[0].r;
	dq2[0].g=dq[0].g;
	dq2[0].b=dq[0].b;
	for(int i=1;i<N;i++){
		dq2[i].r=dq[i].r+mini(dq2[i-1].g,dq2[i-1].b);
		dq2[i].g=dq[i].g+mini(dq2[i-1].r,dq2[i-1].b);
		dq2[i].b=dq[i].b+mini(dq2[i-1].r,dq2[i-1].g);
	}
	int result;
	result=mini(dq2[N-1].r,dq2[N-1].g);
	result=mini(result,dq2[N-1].b);
	cout<<result<<endl;
	return 0;
}
