#include<iostream>
#include<queue>
using namespace std;
int mini = -1;
void searching(int a, int b, int cnt) {
	if (mini < cnt||a<0)
		return;
	if (a == b) {
		mini = cnt;
		return;
	}
	if (b % 2 == 0) {
		searching(a, b/2, cnt + 1);
		searching(a, b-1, cnt + 1);
		searching(a, b+1, cnt + 1);
	}
	else {
		searching(a, b - 1, cnt + 1);
		searching(a, b + 1, cnt + 1);
	}
}
int main(void) {
	int N, K;
	cin >> N >> K;
	mini = K - N;
	if (mini < 0)
		mini = -mini;
	searching(N, K, 0);
	cout << mini << endl;
	return 0;
}
