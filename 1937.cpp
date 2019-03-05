#include<iostream>
#include<stdlib.h>
using namespace std;
//int **arr;
int arr[1000][1000];
int **visit;
int maxx = 0;
void searching(int cnt, int i, int j, int n, int maxim) {
	cnt++;
	visit[i][j] = 1;
	if (i - 1 >= 0 && arr[i - 1][j]>arr[i][j])
		searching(cnt, i - 1, j, n,maxim);
	if (i + 1<n&&arr[i + 1][j]>arr[i][j] )
		searching(cnt, i + 1, j, n,maxim);
	if (j - 1 >= 0 && arr[i][j - 1]>arr[i][j])
		searching(cnt, i, j - 1, n,maxim);
	if (j + 1<n&&arr[i][j + 1]>arr[i][j])
		searching(cnt, i, j + 1, n,maxim);
	if (cnt > maxx)
		maxx = cnt;
	else
		visit[i][j] = 0;
	if (maxx <= maxim)
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
			if (visit[i][j] == 1)continue;
			searching(0, i, j, N,maxim);
			if (maxim<maxx) {
				maxim = maxx;
			}
			maxx = 0;
		}
	}
	cout << maxim << endl;

	return 0;
}
