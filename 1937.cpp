#include<iostream>
#include<stdlib.h>
using namespace std;
//int **arr;
int arr[1000][1000];
int **visit;
void init(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 1;
		}
	}
}
int main(void) {
	int N;
	int maxim = 0;
	int tmp;
	cin >> N;
	visit = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i<N; i++) {
		visit[i] = (int*)malloc(sizeof(int)*N);
	}
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cin >> arr[i][j];
		}
	}
	init(N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i>0&&arr[i-1][j]>arr[i][j]){
				if(visit[i][j]>=visit[i-1][j]||visit[i-1][j]==1){
					visit[i-1][j]=visit[i][j]+1;
					i=i-1;
					j=j-1;
					continue;
				}
			}
			if(i+1<N&&arr[i+1][j]>arr[i][j]){
				if(visit[i][j]>=visit[i+1][j]||visit[i+1][j]==1){
					visit[i+1][j]=visit[i][j]+1;
					i=i+1;
					j=j-1;
					continue;
				}
			}
			if(j>0&&arr[i][j-1]>arr[i][j]){
				if(visit[i][j]>=visit[i][j-1]||visit[i][j-1]==1){
					visit[i][j-1]=visit[i][j]+1;
					j=j-2;
					continue;
				}
			}
			if(j+1<N&&arr[i][j+1]>arr[i][j]){
				if(visit[i][j]>=visit[i][j+1]||visit[i][j+1]==1){
					visit[i][j+1]=visit[i][j]+1;
					continue;
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(visit[i][j]>maxim)
				maxim=visit[i][j];
		}
	}
	cout << maxim << endl;

	return 0;
}
