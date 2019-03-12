#include<iostream>
#include<string>
using namespace std;
int arr[1000][1000];
int dp[1000][1000];
void init(int n,int m){
	for(int i=0;i<n;i++)
	{
		dp[i][0]=arr[i][0];
	}
	for(int i=0;i<m;i++){
		dp[0][i]=arr[0][i];
	}
}
int mini(int a,int b){
	if(a>b)return b;
	else return a;
}
int main(void){
	int N,M;
	int tmp;
	int max=0;
	string st;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		cin>>st;
		for(int j=0;j<M;j++){
			arr[i][j]=st[j]-48;
		}
	}
	init(N,M);
	max=dp[0][0];
	for(int i=1;i<N;i++){
		for(int j=1;j<M;j++){
			if(arr[i][j]==1){
				tmp=mini(dp[i-1][j-1],dp[i][j-1]);
				tmp=mini(dp[i-1][j],tmp);
				dp[i][j]=tmp+1;
				if(dp[i][j]>max)
					max=dp[i][j];
			}
			else if(arr[i][j]==0)
				dp[i][j]=0;
		}
	}

	cout<<max*max<<endl;
	return 0;
}
