#include<iostream>
#include<deque>
using namespace std;
int idx_searching(deque<int> a, int n) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == n)
			return i;
	}
}
int main(void) {
	int N, M;
	int idx;
	int cnt = 0;
	cin >> N >> M;
	deque<int> dq(N);
	deque<int> arr(M);
	for (int i = 0; i < N; i++) {
		dq[i] = i+1;
	}
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	while (arr.empty() != true) {
		if (arr.front() == dq.front())
			dq.pop_front();
		else {
			idx = idx_searching(dq, arr.front());
			if (idx >= dq.size() - idx) {
				for (int i = 0; i < dq.size() - idx; i++) {
					dq.push_front(dq.back());
					dq.pop_back();
					cnt++;
				}
				dq.pop_front();
			}
			else {
				for (int i = 0; i < idx; i++) {
					dq.push_back(dq.front());
					dq.pop_front();
					cnt++;
				}
				dq.pop_front();
			}
		}
		arr.pop_front();
	}
	cout << cnt << endl;
	return 0;
}
