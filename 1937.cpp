#include<iostream>
using namespace std;
int arr[1000][1000];
int visit[1000][1000];
int searching(int N, int i, int j) {
	if (visit[i][j] != 0)return visit[i][j];
	visit[i][j] = 1;
	if (i>0 && arr[i - 1][j]>arr[i][j]) {
		//visit[i - 1][j] = visit[i][j] + 1;
		if(visit[i][j] >= visit[i - 1][j])
			visit[i][j] = searching(N, i - 1, j) + 1;
	}
	if (i + 1<N&&arr[i + 1][j]>arr[i][j]) {
		//visit[i + 1][j] = visit[i][j] + 1;
		if (visit[i][j] >= visit[i + 1][j])
			visit[i][j] = searching(N, i + 1, j) + 1;
	}
	if (j>0 && arr[i][j - 1]>arr[i][j]) {
		//visit[i][j - 1] = visit[i][j] + 1;
		if (visit[i][j] >= visit[i][j - 1])
			visit[i][j] = searching(N, i, j - 1) + 1;
	}
	if (j + 1<N&&arr[i][j + 1]>arr[i][j]) {
		//visit[i][j + 1] = visit[i][j] + 1;
		if (visit[i][j] >= visit[i][j + 1])
			visit[i][j] = searching(N, i, j + 1) + 1;
	}
	return visit[i][j];
}
int main(void) {
	int N;
	int tmp;
	int maxim;
	cin >> N;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cin >> arr[i][j];
		}
	}
	maxim = 1;
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			tmp=searching(N, i, j);
			if (tmp > maxim)
				maxim = tmp;
		}
	}

	cout << maxim << endl;
	return 0;
}
