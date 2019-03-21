#include<iostream>
using namespace std;
int main(void) {
	int N,i=1,tmp;
	int min = -1;
	cin >> N;
	int flag = 0;
	while (N / (5 * i) != 0) {
		i++;
	}
	if (N == 3) {
		cout << 1 << endl;
		return 0;
	}
	for (int j = 0; j < i; j++) {
		if ((N - (5 * j)) % 3 == 0) {
			flag = 1;
			int cnt = (N - (5 * j)) / 3;
			if (min == -1)min = cnt + j;
			else if (min > cnt + j)min = cnt + j;
		}
	}
	if (flag == 1)
		cout << min << endl;
	else if (flag == 0)
		cout << -1 << endl;

	return 0;
}
