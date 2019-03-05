#include<iostream>
#include<stdlib.h>
using namespace std;
int **arr;
int maxx=0;
void searching(int cnt,int i,int j,int n){
	cnt++;
	int tmp;
	if(i-1>=0&&arr[i-1][j]>arr[i][j])
		searching(cnt,i-1,j,n);
	if(i+1<n&&arr[i+1][j]>arr[i][j])
		searching(cnt,i+1,j,n);
	if(j-1>=0&&arr[i][j-1]>arr[i][j])
		searching(cnt,i,j-1,n);
	if(j+1<n&&arr[i][j+1]>arr[i][j])
		searching(cnt,i,j+1,n);
	if(cnt>maxx)
		maxx=cnt;
}
int main(void){
	int N;
	int maxim=0;
	int tmp;
	cin>>N;
	arr=(int**)malloc(sizeof(int*)*N);
	for(int i=0;i<N;i++){
		arr[i]=(int*)malloc(sizeof(int)*N);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			searching(0,i,j,N);
			if(maxim<maxx){
				maxim=maxx;
			}
			maxx=0;
		}
	}
	cout<<maxim<<endl;

	return 0;
}
