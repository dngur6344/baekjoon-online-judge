#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
deque<int> dq;
deque<int> dq2;
int max_val=0;
void finding(deque<int> visit,int cnt,int start){
	int tmp;
	if(start==dq2.size()){
		if(cnt>max_val)max_val=cnt;
		return;
	}
	for(int i=start;i<dq2.size();i++){
		if(visit[i]==0){
			tmp=dq2[i];
			for(int j=0;j<dq.size();j++){
				if(dq[j]>=dq2[i]){
					dq[j]=dq[j]-tmp;
					visit[i]=1;
					finding(visit,cnt+1,i+1);
					visit[i]=0;
					dq[j]=dq[j]+tmp;
				}
			}
		}
	}
}
int main(void){
	int M,N,tmp;
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>tmp;
		dq.push_back(tmp);
	}
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tmp;
		dq2.push_back(tmp);
	}
	deque<int> visit(N,0);
	//sort(dq.begin(),dq.end(),greater<int>());
	//sort(dq2.begin(),dq2.end());
	finding(visit,0,0);
	cout<<max_val<<endl;
	return 0;
}
