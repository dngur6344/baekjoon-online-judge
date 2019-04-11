#include<iostream>
#include<deque>
using namespace std;
struct point{
	int x;
	int y;
};
deque<point> ice;
int **arr;
int **arr2;
int visit[300][300];
void finding(int n,int m){
	point tmp;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=0){
				tmp.x=i;
				tmp.y=j;
				ice.push_back(tmp);
			}
		}
	}
}
void init_visit(int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visit[i][j]=0;
			arr[i][j]=arr2[i][j];
		}
	}
}
void DFS(int n,int m,int cur_x,int cur_y){
	visit[cur_x][cur_y]=1;
	if(cur_x>0&&visit[cur_x-1][cur_y]==0&&arr2[cur_x-1][cur_y]!=0){
		//visit[cur_x-1][cur_y]=1;
		DFS(n,m,cur_x-1,cur_y);
	}
	if(cur_x<n-1&&visit[cur_x+1][cur_y]==0&&arr2[cur_x+1][cur_y]!=0){
		//visit[cur_x+1][cur_y]=1;
		DFS(n,m,cur_x+1,cur_y);
	}
	if(cur_y>0&&visit[cur_x][cur_y-1]==0&&arr2[cur_x][cur_y-1]!=0){
		//visit[cur_x][cur_y-1]=1;
		DFS(n,m,cur_x,cur_y-1);
	}
	if(cur_y<m-1&&visit[cur_x][cur_y+1]==0&&arr2[cur_x][cur_y+1]!=0){
		//visit[cur_x][cur_y+1]=1;
		DFS(n,m,cur_x,cur_y+1);
	}
}
int resulting(){
	deque<point> :: iterator im;
	for(im=ice.begin();im!=ice.end();im++){
		if(visit[(*im).x][(*im).y]==0){
			return 1;
		}
	}
	return 0;
}
int main(){
	int tmp_x,tmp_y;
	int n,m;
	point temper;
	cin>>n>>m;
	arr=new int*[n];
	arr2=new int*[n];
	for(int i=0;i<n;i++){
		arr[i]=new int[m];
		arr2[i]=new int[m];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			arr2[i][j]=arr[i][j];
		}
	}
	int res;
	int cnt=0;
	finding(n,m);
	//init_visit(n,m);
	DFS(n,m,ice[0].x,ice[0].y);
	res=resulting();
	if(res==1){
		cout<<0<<endl;
		return 0;
	}
	init_visit(n,m);
	for(cnt=1;;cnt++){
		int tmp=ice.size();
		for(int i=0;i<tmp;i++){
			tmp_x=ice[0].x;
			tmp_y=ice[0].y;
			if(tmp_x>0&&arr[tmp_x-1][tmp_y]==0)
				arr2[tmp_x][tmp_y]-=1;
			if(tmp_x<n-1&&arr[tmp_x+1][tmp_y]==0)
				arr2[tmp_x][tmp_y]-=1;
			if(tmp_y>0&&arr[tmp_x][tmp_y-1]==0)
				arr2[tmp_x][tmp_y]-=1;
			if(tmp_y<m-1&&arr[tmp_x][tmp_y+1]==0)
				arr2[tmp_x][tmp_y]-=1;
			if(arr2[tmp_x][tmp_y]<=0)
				arr2[tmp_x][tmp_y]=0;
			else{
				temper.x=tmp_x;
				temper.y=tmp_y;
				ice.push_back(temper);
			}
			ice.pop_front();
		}
		if(ice.size()==0){
			cout<<0<<endl;
			return 0;
		}
		DFS(n,m,ice[0].x,ice[0].y);
		res=resulting();
		if(res==1)break;
		init_visit(n,m);
	}
	cout<<cnt<<endl;
	return 0;
}
