#include<iostream>
#include<queue>
using namespace std;
int mini = -1;
void searching(int a, int b, int cnt) {
	if (mini < cnt || a<0)
		return;
	if (a == b) {
		mini = cnt;
		return;
	}
	if (b % 2 == 0) {
		searching(a, b / 2, cnt + 1);
		searching(a, b - 1, cnt + 1);
		searching(a, b + 1, cnt + 1);
	}
	else {
		searching(a, b - 1, cnt + 1);
		searching(a, b + 1, cnt + 1);
	}
}
int chai(int a, int b) {
	int tmp = a - b;
	if (tmp < 0)
		tmp = -tmp;
	return tmp;
}
int main(void) {
	int N, K;
	int tmp1,tmp2,cnt=0;
	cin >> N >> K;
	tmp1 = N;
	while (tmp1 < K) {
		tmp2 = tmp1;
		tmp1 = tmp1 * 2;
		if (chai(tmp2, K) < chai(tmp1, K))
			break;
		cnt++;
	}
	mini = K-tmp2+cnt;
	if (mini < 0)
		mini = -mini;
	searching(N, K, 0);
	cout << mini << endl;
	return 0;
}
