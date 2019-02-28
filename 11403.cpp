#include<iostream>
#include<stdlib.h>
using namespace std;
int arr[100][100];
int visit[100]={0,};
int flag=0;
void init(int a){
	for(int i=0;i<a;i++){
		visit[i]=0;
	}
}
void calc(int a,int b,int n){
	if(arr[a][b]==1){
		flag=1;
	}
	if(flag==1)
		return;
	else{
		visit[a]=1;
		for(int i=0;i<n;i++){
			if(arr[a][i]==1&&visit[i]==0){
				calc(i,b,n);
			}
		}
	}
}
int main(void){
	int N,i,j;
	cin>>N;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			cin>>arr[i][j];
		}
	}

	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			init(N);
			flag=0;
			calc(i,j,N);
			if(flag==1)
				cout<<1<<" ";
			else if(flag==0)
				cout<<0<<" ";
		}
		cout<<endl;
	}

	return 0;
}
