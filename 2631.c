#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int N;
	int i, j, k, tmp, cnt = 0,max=0;
	int arr[201];
	int res[201];
	scanf("%d", &N);
	for (i = 1;i <=N;i++)
	{
		scanf("%d", &arr[i]);
	}
	res[1] = 1;
	for (i = 2;i <= N;i++)
	{
		for (j = 1;j < i;j++)
		{
			if (arr[j] < arr[i] && max < res[j])
			{
				max = res[j];
			}
		}
		res[i] = max + 1;
		max = 0;
	}
	max = res[1];
	for (i = 1;i <= N;i++)
	{
		if (max < res[i])max = res[i];
	}
	cnt = N - max;
	printf("%d", cnt);
	return 0;
}
