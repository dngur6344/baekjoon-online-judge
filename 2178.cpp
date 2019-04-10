#include<string>
#include<deque>
#include<iostream>
using namespace std;
deque<string> dq;
struct two{
	int x;
	int y;
};
deque<two> dq2;
int** visit;
int bfs(int x,int y){
	int tmp=dq2.size();
	int tmp_x,tmp_y;
	two temper;
	for(int cnt=1;;cnt++){
		for(int i=0;i<tmp;i++){
			if(dq2[0].x==x&&dq2[0].y==y){
				return cnt;
			}
			tmp_x=dq2[0].x;
			tmp_y=dq2[0].y;
			if(tmp_x>0&&visit[tmp_x-1][tmp_y]==0&&dq[tmp_x-1][tmp_y]=='1'){
				visit[tmp_x-1][tmp_y]=1;
				temper.x=tmp_x-1;
				temper.y=tmp_y;
				dq2.push_back(temper);
			}
			if(tmp_x<x&&visit[tmp_x+1][tmp_y]==0&&dq[tmp_x+1][tmp_y]=='1'){
				visit[tmp_x+1][tmp_y]=1;
				temper.x=tmp_x+1;
				temper.y=tmp_y;
				dq2.push_back(temper);
			}
			if(tmp_y>0&&visit[tmp_x][tmp_y-1]==0&&dq[tmp_x][tmp_y-1]=='1'){
				visit[tmp_x][tmp_y-1]=1;
				temper.x=tmp_x;
				temper.y=tmp_y-1;
				dq2.push_back(temper);
			}
			if(tmp_y<y&&visit[tmp_x][tmp_y+1]==0&&dq[tmp_x][tmp_y+1]=='1'){
				visit[tmp_x][tmp_y+1]=1;
				temper.x=tmp_x;
				temper.y=tmp_y+1;
				dq2.push_back(temper);
			}
			dq2.pop_front();
		}
		tmp=dq2.size();
	}
}
int main(void){
	int n,m;
	string st;
	cin>>n>>m;
	visit=new int*[n];
	for(int i=0;i<n;i++){
		visit[i]=new int[m];
		for(int j=0;j<m;j++)
			visit[i][j]=0;
	}
	for(int i=0;i<n;i++){
		cin>>st;
		dq.push_back(st);
	}
	int res;
	two imp;
	imp.x=0;
	imp.y=0;
	dq2.push_back(imp);
	visit[0][0]=1;
	res=bfs(n-1,m-1);
	cout<<res<<endl;
	return 0;
}
