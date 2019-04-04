#include<iostream>
#include<deque>
using namespace std;
deque<int> arr;
deque<int> arr2;
int visiting(deque<int> dq,int x,int y){
	int cnt1=0;
	int cnt2=1;
	arr.push_back(x);
	while(arr[0]!=0){
		for(int i=1;i<dq.size();i++){
			if(arr[0]==dq[i]){
				arr2.push_back(i);
			}
		}
		int tmp;
		while(arr2.empty()!=true){
			tmp=arr2.size();
			for(int i=0;i<tmp;i++){
				if(arr2[0]==y)
					return cnt1+cnt2;
				for(int j=1;j<dq.size();j++){
					if(arr2[0]==dq[j]){
						arr2.push_back(j);
					}
				}
				arr2.pop_front();
			}
			cnt2++;
		}
		arr.push_back(dq[arr[0]]);
		arr.pop_front();
		cnt1++;
		cnt2=1;
		if(arr[0]==y)
			return cnt1;
	}
	return -1;
}
int main(void){
	int n,m;
	int tmp,tmp2,x,y;
	cin>>n;
	cin>>x>>y;
	cin>>m;
	deque<int> dq(n+1,0);
	for(int i=0;i<m;i++){
		cin>>tmp>>tmp2;
		dq[tmp2]=tmp;
	}
	int cnt;
	cnt=visiting(dq,x,y);
	cout<<cnt<<endl;

	return 0;
}
