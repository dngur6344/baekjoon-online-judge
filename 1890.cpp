#include<iostream>
using namespace std;
int arr[100][100];
int res[100][100];
int main(void){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>arr[i][j];
			res[i][j]=0;
		}
	}
	res[0][0]=1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			int val=arr[i][j];
			if(i==N-1&&j==N-1)break;
			if(val+i<N){
				res[val+i][j]+=res[i][j];
			}
			if(val+j<N){
				res[i][val+j]+=res[i][j];
			}
		}
	}
	cout<<res[N-1][N-1]<<endl;
	return 0;
}
