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
	searching(a - 1, b, cnt+1);
	searching(a + 1, b, cnt+1);
	searching(2 * a, b, cnt+1);
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
