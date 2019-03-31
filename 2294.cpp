#include<stdio.h>
#include<stdlib.h>
void sort(int *arr);
int main(void)
{
	int n, k;
	int res[10001] = { 0, };
	int arr[101] = { 10001, };
	int i, j;
	int min;
	scanf("%d %d", &n, &k);
	for (i = 0;i < n;i++)
		scanf("%d", &arr[i]);
	sort(arr);
	for (i = 1;i <= k;i++)
	{
		min = 100000;
		for (j = 0;j < n;j++)
		{
			if (i < arr[n-1])
			{
				res[i] = 0;
				break;
			}
			if (arr[j] == i)
			{
				res[i] = 1;
				break;
			}
			if (i > arr[j]&&res[i-arr[j]]!=0)
			{
				if (min > res[i - arr[j]])min = res[i - arr[j]];
			}
		}
		if (min != 100000&&i!=arr[j])
		{
			res[i] = min + 1;
		}
	}
	if (res[k] == 0)printf("-1\n");
	else
	{
		printf("%d\n", res[k]);
	}
	return 0;
}
void sort(int *arr)
{
	int i, j;
	int tmp;
	for (i = 0;i < 100;i++)
	{
		for (j = i + 1;j < 101;j++)
		{
			if (arr[i] < arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
