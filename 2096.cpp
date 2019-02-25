#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
int maxim(int a, int b, int c)
{
	a = max(a, b);
	a = max(a, c);
	return a;
}
int minim(int a, int b, int c)
{
	a = min(a, b);
	a = min(a, c);
	return a;
}
int main(void)
{
	int num;
	int i, j, k;
	int arr[100000][3];
	int res_max[100000][3];
	int result_max, result_min;
	scanf("%d", &num);
	for (i = 0;i < num;i++)
	{
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
	res_max[0][0] = arr[0][0];
	res_max[0][1] = arr[0][1];
	res_max[0][2] = arr[0][2];
	for (i = 1;i < num;i++)
	{
		res_max[i][1] = maxim(res_max[i - 1][0], res_max[i - 1][1], res_max[i - 1][2])+arr[i][1];
		res_max[i][0] = max(res_max[i - 1][0], res_max[i - 1][1])+arr[i][0];
		res_max[i][2] = max(res_max[i - 1][2], res_max[i - 1][1])+arr[i][2];
	}
	result_max = maxim(res_max[num - 1][0], res_max[num - 1][1], res_max[num - 1][2]);
	for (i = 1;i < num;i++)
	{
		res_max[i][1] = minim(res_max[i - 1][0], res_max[i - 1][1], res_max[i - 1][2]) + arr[i][1];
		res_max[i][0] = min(res_max[i - 1][0], res_max[i - 1][1]) + arr[i][0];
		res_max[i][2] = min(res_max[i - 1][2], res_max[i - 1][1]) + arr[i][2];
	}
	result_min = minim(res_max[num - 1][0], res_max[num - 1][1], res_max[num - 1][2]);
	printf("%d %d", result_max, result_min);
	return 0;
}
