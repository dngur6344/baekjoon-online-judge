#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
class two{
private:
public:
	int val;
	int visit;
};
deque<int> dq;
deque<two> dq2;
int max_val=0;
int min_search(){
	int res=dq2[0].val;
	for(int i=1;i<dq2.size();i++){
		if(dq2[i].visit==0&&dq2[i].val<res)
			res=dq2[i].val;
	}
	return res;
}
int max_search(){
	int res=dq[0];
	for(int i=1;i<dq.size();i++){
		if(dq[i]>res)
			res=dq[i];
	}
	return res;
}
void finding(int cnt,int start){
	int tmp;
	if(min_search()>max_search()){
		if(cnt>max_val)max_val=cnt;
		return;
	}
	for(int i=start;i<dq2.size();i++){
		if(dq2[i].visit==0){
			tmp=dq2[i].val;
			for(int j=0;j<dq.size();j++){
				if(dq[j]>=dq2[i].val){
					dq[j]=dq[j]-tmp;
					dq2[i].visit=1;
					finding(cnt+1,i+1);
					dq2[i].visit=0;
					dq[j]=dq[j]+tmp;
				}
			}
		}
	}
}
int main(void){
	int M,N,tmp;
	two temper;
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>tmp;
		dq.push_back(tmp);
	}
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tmp;
		temper.val=tmp;
		temper.visit=0;
		dq2.push_back(temper);
	}
	//sort(dq.begin(),dq.end(),greater<int>());
	//sort(dq2.begin(),dq2.end());
	finding(0,0);
	cout<<max_val<<endl;
	return 0;
}
