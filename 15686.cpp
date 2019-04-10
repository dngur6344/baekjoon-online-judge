#include<iostream>
#include<deque>
using namespace std;
struct point{
	int x;
	int y;
};
deque<point> dq1;
deque<point> dq2;
deque<point> dq3;
int **arr;
int cnt;
int res_tmp;
int visit[13]={0,};
void searching(int num,int start){
	int tmp_x,tmp_y;
	int res=0;
	res_tmp=100000;
	if(num==dq3.size()){
		for(int i=0;i<dq1.size();i++){
			for(int j=0;j<num;j++){
				tmp_x=dq1[i].x-dq3[j].x;
				if(tmp_x<0)tmp_x=-tmp_x;
				tmp_y=dq1[i].y-dq3[j].y;
				if(tmp_y<0)tmp_y=-tmp_y;
				if(tmp_x+tmp_y<res_tmp)res_tmp=tmp_x+tmp_y;
			}
			res+=res_tmp;
			res_tmp=100000;
		}
		if(res<cnt)cnt=res;
		return;
	}
	for(int i=start;i<dq2.size();i++){
		if(visit[i]==0){
			visit[i]=1;
			dq3.push_back(dq2[i]);
			searching(num,i+1);
			visit[i]=0;
			dq3.pop_back();
		}
	}
}
int main(){
	int n,m;
	point temp;
	cin>>n>>m;
	arr=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[n];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j]==1){
				temp.x=i;
				temp.y=j;
				dq1.push_back(temp);
			}
			else if(arr[i][j]==2){
				temp.x=i;
				temp.y=j;
				dq2.push_back(temp);
			}
		}
	}
	cnt=100000;
	searching(m,0);
	cout<<cnt<<endl;
	return 0;
}
