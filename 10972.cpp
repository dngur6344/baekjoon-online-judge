#include<iostream>
#include<stdlib.h>
using namespace std;
void sorting(int *a,int n){
	int i,j,tmp;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}
int main(void){
	int n;
	int arr[10000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	if(n==1){
		cout<<"-1"<<endl;
		return 0;
	}
	int tmp=n-2;
	int bi=arr[tmp];
	if(arr[tmp]<arr[tmp+1]){
		int bi=arr[tmp];
		arr[tmp]=arr[tmp+1];
		arr[tmp+1]=bi;
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	else{
		int j=3;
		while(true){
			if(n-j<0){
				cout<<"-1"<<endl;
				break;
			}
			tmp=arr[n-j];
			int minim=10002;
			int minim_idx;
			for(int i=n-j+1;i<n;i++){
				if(arr[i]>tmp&&arr[i]<minim){
					minim=arr[i];
					minim_idx=i;
				}
			}
			if(minim==10002){
				j=j+1;
				continue;
			}
			else{
				bi=arr[n-j];
				arr[n-j]=arr[minim_idx];
				arr[minim_idx]=bi;
				int *res;
				res=(int*)malloc(sizeof(int)*(j-1));
				for(int i=n-j+1;i<n;i++){
					res[i-n+j-1]=arr[i];
				}
				sorting(res,j-1);
				for(int i=n-j+1;i<n;i++){
					arr[i]=res[i-n+j-1];
				}
				for(int i=0;i<n;i++){
					cout<<arr[i]<<" ";
				}
				cout<<endl;
				break;
			}
		}
	}
	return 0;
}
