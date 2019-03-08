#include<iostream>
using namespace std;
//int **arr;
int arr[1000][1000];
int visit[1000][1000];
int maxim=0;
int max_i=-1;
int max_j=-1;
int flag=0;
void init(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 1;
		}
	}
}
void searching(int N,int i,int j){
	if(maxim<visit[i][j]){
		maxim=visit[i][j];
		flag=1;
	}
	if(i>0&&arr[i-1][j]>arr[i][j]){
		if(visit[i][j]>=visit[i-1][j]||visit[i-1][j]==1){
			if(i==max_i&&j==max_j){
				maxim+=visit[i][j];
			}
			else{
				visit[i-1][j]=visit[i][j]+1;
				searching(N,i-1,j);
			}
		}
	}
	if(i+1<N&&arr[i+1][j]>arr[i][j]){
		if(visit[i][j]>=visit[i+1][j]||visit[i+1][j]==1){
			if(i==max_i&&j==max_j){
				maxim+=visit[i][j];
			}
			else{
				visit[i+1][j]=visit[i][j]+1;
				searching(N,i+1,j);
			}
		}
	}
	if(j>0&&arr[i][j-1]>arr[i][j]){
		if(visit[i][j]>=visit[i][j-1]||visit[i][j-1]==1){
			if(i==max_i&&j==max_j){
				maxim+=visit[i][j];
			}
			else{
				visit[i][j-1]=visit[i][j]+1;
				searching(N,i,j-1);
			}
		}
	}
	if(j+1<N&&arr[i][j+1]>arr[i][j]){
		if(visit[i][j]>=visit[i][j+1]||visit[i][j+1]==1){
			if(i==max_i&&j==max_j){
				maxim+=visit[i][j];
			}
			else{
				visit[i][j+1]=visit[i][j]+1;
				searching(N,i,j+1);
			}
		}
	}
}
int main(void) {
	int N;
	int tmp;
	cin >> N;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cin >> arr[i][j];
		}
	}
	init(N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(visit[i][j]==1)
				searching(N,i,j);
				if(flag==1){
					max_i=i;
					max_j=j;
					flag=0;
				}
		}
	}
	cout << maxim << endl;
	return 0;
}
