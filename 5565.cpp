#include<iostream>
using namespace std;
int main(void) {
	int N, tmp;
	int sum = 0;
	cin >> N;
	for (int i = 0; i < 9; i++) {
		cin >> tmp;
		sum += tmp;
	}
	cout << N - sum << endl;
	return 0;
}
