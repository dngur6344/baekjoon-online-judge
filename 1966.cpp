#include<iostream>
#include<deque>
using namespace std;
struct two{
	int m;
	int n;
};
deque<two> dq;
deque<deque<two> >dq2;
int *res;
void finding(int idx){
	int i;
	int cnt=1;
	while(dq2[idx].empty()==false){
		for(i=0;i<dq2[idx].size();i++){
			if(dq2[idx][i].m>dq2[idx][0].m){
				dq2[idx].push_back(dq2[idx][0]);
				dq2[idx].pop_front();
				break;
			}
		}
		if(i!=dq2[idx].size())continue;
		else{
			if(dq2[idx][0].n==1){
				res[idx]=cnt;
				return;
			}
			else{
				dq2[idx].pop_front();
				cnt++;
			}
		}
	}
}
int main(void){
	int n;
	int tmp,tmp2;
	two am;
	cin>>n;
	res=new int[n];
	for(int i=0;i<n;i++){
		cin>>tmp>>tmp2;
		for(int j=0;j<tmp;j++){
			cin>>am.m;
			if(j==tmp2)am.n=1;
			else am.n=0;
			dq.push_back(am);
		}
		dq2.push_back(dq);
		dq.clear();
	}
	for(int i=0;i<n;i++){
		finding(i);
	}
	for(int i=0;i<n;i++)
		cout<<res[i]<<endl;
  return 0;
}
