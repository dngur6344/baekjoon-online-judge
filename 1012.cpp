#include<stdio.h>
#include<stdlib.h>
int seak(int arr[50][50], int tmp1, int tmp2);
void find(int arr[50][50], int tmp1, int tmp2,int ga, int se);
int main(void)
{
	int num;
	int i, j,k;
	int arr[50][50];
	int ga, se, bae;
	int *res;
	int tmp, tmp1;
	scanf("%d", &num);
	res = (int*)malloc(sizeof(int)*num);
	for (i = 0;i < num;i++)
	{
		scanf("%d %d %d", &ga, &se, &bae);
		for (j = 0;j < 50;j++)
		{
			for (k = 0;k < 50;k++)
			{
				arr[j][k] = 0;
			}
		}
		for (j = 0;j < bae;j++)
		{
			scanf("%d %d", &tmp, &tmp1);
			arr[tmp1][tmp] = 1;
		}
		res[i] = seak(arr, ga, se);
	}
	for (i = 0;i < num;i++)
		printf("%d\n", res[i]);
	return 0;
}
int seak(int arr[50][50], int tmp1, int tmp2)
{
	int cnt = 0;
	int i, j;
	for (i = 0;i < tmp2;i++)
	{
		for (j = 0;j < tmp1;j++)
		{
			if (arr[i][j] == 1)
			{
				cnt +=1;
				find(arr, i, j,tmp1,tmp2);
			}
		}
	}
	return cnt;
}
void find(int arr[50][50], int tmp1, int tmp2,int ga,int se)
{
	int i, j;
	arr[tmp1][tmp2] = 0;
	if (tmp1 - 1 >= 0 && arr[tmp1 - 1][tmp2] == 1)
		find(arr, tmp1 - 1, tmp2,ga,se);
	if (tmp2 - 1 >= 0 && arr[tmp1][tmp2 - 1] == 1)
		find(arr, tmp1, tmp2 - 1,ga,se);
	if (tmp1 + 1 < se && arr[tmp1 + 1][tmp2] == 1)
		find(arr, tmp1 + 1, tmp2,ga,se);
	if (tmp2 + 1 < ga && arr[tmp1][tmp2 + 1] == 1)
		find(arr, tmp1, tmp2 + 1,ga,se);
}
