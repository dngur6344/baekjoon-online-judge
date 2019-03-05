#include<iostream>
#include<stdlib.h>
using namespace std;
//int **arr;
int arr[1000][1000];
int **visit;
int maxx = 0;
void searching(int cnt, int i, int j, int n) {
	cnt++;
	visit[i][j] = 1;
	if (i - 1 >= 0 && arr[i - 1][j]>arr[i][j]&&visit[i-1][j]==0)
		searching(cnt, i - 1, j, n);
	if (i + 1<n&&arr[i + 1][j]>arr[i][j] && visit[i+1][j] == 0)
		searching(cnt, i + 1, j, n);
	if (j - 1 >= 0 && arr[i][j - 1]>arr[i][j] && visit[i][j-1] == 0)
		searching(cnt, i, j - 1, n);
	if (j + 1<n&&arr[i][j + 1]>arr[i][j] && visit[i][j+1] == 0)
		searching(cnt, i, j + 1, n);
	if (cnt>maxx)
		maxx = cnt;
	visit[i][j] = 0;
	return;
}
void init(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = 0;
		}
	}
}
int main(void) {
	int N;
	int maxim = 0;
	int tmp;
	cin >> N;
	visit = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i<N; i++) {
		visit[i] = (int*)malloc(sizeof(int)*N);
	}
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			cin >> arr[i][j];
		}
	}
	init(N);
	for (int i = 0; i<N; i++) {
		for (int j = 0; j<N; j++) {
			searching(0, i, j, N);
			if (maxim<maxx) {
				maxim = maxx;
			}
			maxx = 0;
		}
	}
	cout << maxim << endl;

	return 0;
}
