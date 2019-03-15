#include<iostream>
#include<deque>
using namespace std;
int main(void) {
	int N, M,cnt=0;
	cin >> N;
	deque<int> dq(N);
	deque<int> arr;
	for (int i = 0; i < N; i++) {
		cin >> dq[i];
	}
	cin >> M;
	dq[M] = -2;
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] == M) {
			arr.push_back(i);
		}
	}
	while (arr.empty() != true) {
		for (int i = 0; i < dq.size(); i++) {
			if (dq[i] == arr.front()) {
				arr.push_back(i);
				dq[arr.front()] = -2;
			}
		}
		arr.pop_front();
	}
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] == -2 || dq[i] == -1)continue;
		for (int j = 0; j < dq.size(); j++) {
			if (i == dq[j]) {
				arr.push_back(j);
				dq[i] = -2;
			}
		}
		while (arr.empty() != true) {
			for (int j = 0; j < dq.size(); j++) {
				if (dq[j] == arr.front()) {
					arr.push_back(j);
					dq[arr.front()] = -2;
				}
			}
			arr.pop_front();
		}
	}
	for (int i = 0; i < dq.size(); i++) {
		if (dq[i] != -2 && dq[i] != -1)cnt++;
	}
	cout << cnt << endl;
	return 0;
}
