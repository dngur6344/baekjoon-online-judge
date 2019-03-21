#include<iostream>
#include<deque>
using namespace std;
deque<int> dq;
int cnt=0;
int visit[20];
void calc(int n,int cur_n,int next, int sum,int cur_sum, int count) {
	if (count == cur_n) {
		if (sum == cur_sum)
			cnt++;
		return;
	}
	for (int i = next; i < n; i++) {
		visit[i] = 1;
		calc(n, cur_n, i+1, sum, cur_sum+dq[i], count+1);
		visit[i] = 0;
	}
}
int main(void) {
	int n, s, tmp;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		dq.push_back(tmp);
	}
	for (int i = 1; i <= dq.size(); i++) {
		calc(n, i, 0, s, 0, 0);
	}
	cout << cnt << endl;

	return 0;
}
