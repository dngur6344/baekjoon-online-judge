#include<iostream>
#include<queue>
using namespace std;
int mini = -1;
int visit[100001] = { 0, };
queue<int> q;
void searching(int a, int b) {
	int tmp;
	int cnt = 0;
	int num;
	q.push(a);
	while (!q.empty()) {
		int num = q.size();
		for (int i = 0; i < num; i++) {
			tmp = q.front();
			if (tmp == b) {
				mini = cnt;
				return;
			}
			if (tmp + 1 <= 100000 &&visit[tmp + 1] == 0) {
				q.push(tmp + 1);
				visit[tmp + 1] = 1;
			}
			if (tmp - 1 >= 0&&visit[tmp - 1] == 0 ) {
				q.push(tmp - 1);
				visit[tmp - 1] = 1;
			}
			if (tmp * 2 <= 100000&&visit[tmp * 2] == 0) {
				q.push(tmp * 2);
				visit[tmp * 2] = 1;
			}
			q.pop();
		}
		cnt++;
	}
}
int main(void) {
	int N, K;
	int tmp1,tmp2,cnt=0;
	cin >> N >> K;
	searching(N, K);
	cout << mini << endl;
	return 0;
}
