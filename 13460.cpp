#include<string>
#include<iostream>
#include<deque>
using namespace std;
struct coor{
	int row;
	int col;
};
struct double_coor{
	coor red;
	coor blue;
};
coor R;
coor B;
coor hole;
deque<string> pan;
deque<double_coor> dq;
void finding_RB(int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(pan[i][j]=='R'){
				R.row=i;
				R.col=j;
				pan[i][j]='.';
			}
			if(pan[i][j]=='O')
			{
				hole.row=i;
				hole.col=j;
				pan[i][j]='.';
			}
			if(pan[i][j]=='B'){
				B.row=i;
				B.col=j;
				pan[i][j]='.';
			}
		}
	}
}
coor rotate(int direction,coor cur,coor ban){
	coor temp;
	if(direction==1){
		if(cur.row==hole.row&&cur.col==hole.col)
			return cur;
		if((cur.col+1!=ban.col||cur.row!=ban.row)&&pan[cur.row][cur.col+1]!='#'){
			temp.row=cur.row;
			temp.col=cur.col+1;
			return rotate(1,temp,ban);
		}
		return cur;
	}
	else if(direction==2){
		if(cur.row==hole.row&&cur.col==hole.col)
			return cur;
		if((cur.col-1!=ban.col||cur.row!=ban.row)&&pan[cur.row][cur.col-1]!='#'){
			temp.row=cur.row;
			temp.col=cur.col-1;
			return rotate(2,temp,ban);
		}
		return cur;
	}
	else if(direction==3){
		if(cur.row==hole.row&&cur.col==hole.col)
			return cur;
		if((cur.row+1!=ban.row||cur.col!=ban.col)&&pan[cur.row+1][cur.col]!='#'){
			temp.row=cur.row+1;
			temp.col=cur.col;
			return rotate(3,temp,ban);
		}
		return cur;
	}
	else if(direction==4){
		if(cur.row==hole.row&&cur.col==hole.col)
			return cur;
		if((cur.row-1!=ban.row||cur.col!=ban.col)&&pan[cur.row-1][cur.col]!='#'){
			temp.row=cur.row-1;
			temp.col=cur.col;
			return rotate(4,temp,ban);
		}
		return cur;
	}
}
int main(void){
	int n,m,coor_len;
	string st;
	double_coor tmp;
	coor nope;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>st;
		pan.push_back(st);
	}
	finding_RB(n,m);


	nope.col=0;
	nope.row=0;
	tmp.red=R;
	tmp.blue=B;
	dq.push_back(tmp);
	for(int i=0;i<=10;i++){
		coor_len=dq.size();
		for(int j=0;j<coor_len;j++){
			if(dq[0].red.row==hole.row&&dq[0].red.col==hole.col){
				if(!(dq[0].blue.row==hole.row&&dq[0].blue.col==hole.col)){
					cout<<i<<endl;
					return 0;
				}
			}
			if(dq[0].red.row>dq[0].blue.row){
				tmp.red=rotate(3,dq[0].red,nope);//red south(3)
				if(tmp.red.row==hole.row&&tmp.red.col==hole.col)
					tmp.blue=rotate(3,dq[0].blue,nope);
				else
					tmp.blue=rotate(3,dq[0].blue,tmp.red);//blue south(3)
				dq.push_back(tmp);
				tmp.blue=rotate(4,dq[0].blue,nope);//blue north(4)
				tmp.red=rotate(4,dq[0].red,tmp.blue);//red north(4)
				dq.push_back(tmp);
			}
			else{
				tmp.blue=rotate(3,dq[0].blue,nope);//blue south(3)
				tmp.red=rotate(3,dq[0].red,tmp.blue);//red south(3)
				dq.push_back(tmp);
				tmp.red=rotate(4,dq[0].red,nope);//red north(4)
				if(tmp.red.row==hole.row&&tmp.red.col==hole.col)
					tmp.blue=rotate(4,dq[0].blue,nope);//blue north(4)
				else
					tmp.blue=rotate(4,dq[0].blue,tmp.red);//blue north(4)
				dq.push_back(tmp);
			}
			if(dq[0].red.col>dq[0].blue.col){
				tmp.red=rotate(1,dq[0].red,nope);//red east(1)
				if(tmp.red.row==hole.row&&tmp.red.col==hole.col)
					tmp.blue=rotate(1,dq[0].blue,nope);//blue east(1)
				else
					tmp.blue=rotate(1,dq[0].blue,tmp.red);//blue east(1)
				dq.push_back(tmp);
				tmp.blue=rotate(2,dq[0].blue,nope);//blue west(2)
				tmp.red=rotate(2,dq[0].red,tmp.blue);//red west(2)
				dq.push_back(tmp);
			}
			else{
				tmp.blue=rotate(1,dq[0].blue,nope);//blue east(1)
				tmp.red=rotate(1,dq[0].red,tmp.blue);//red east(1)
				dq.push_back(tmp);
				tmp.red=rotate(2,dq[0].red,nope);//red west(2)
				if(tmp.red.row==hole.row&&tmp.red.col==hole.col)
					tmp.blue=rotate(2,dq[0].blue,nope);//blue west(2)
				else
					tmp.blue=rotate(2,dq[0].blue,tmp.red);//blue west(2)
				dq.push_back(tmp);
			}
			dq.pop_front();
		}
	}
	cout<<-1<<endl;
	return 0;
}
