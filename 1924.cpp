#include<iostream>
using namespace std;
int main(void){
	int M,D;
	cin>>M>>D;
	int count=0;
	for(int i=1;i<M;i++){
		if(i==2){
			count+=28;
			continue;
		}
		if((i<8&&i%2==1)||(i>=8&&i%2==0)){
			count+=31;
		}
		else if((i<8&&i%2==0)||(i>=8&&i%2==1)){
			count+=30;
		}
	}
	count+=D;
	if(count%7==0)
		cout<<"SUN"<<endl;
	else if(count%7==1)
		cout<<"MON"<<endl;
	else if(count%7==2)
		cout<<"TUE"<<endl;
	else if(count%7==3)
		cout<<"WED"<<endl;
	else if(count%7==4)
		cout<<"THU"<<endl;
	else if(count%7==5)
		cout<<"FRI"<<endl;
	else if(count%7==6)
		cout<<"SAT"<<endl;
	return 0;
}
