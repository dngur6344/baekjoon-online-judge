#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
int main(void)
{
	int arr[1000];
	long long res[1000];
	int num;
	int i, j;
	long long maxim;
	scanf("%d", &num);
	for (i = 0;i < num;i++)
	{
		scanf("%d", &arr[i]);
	}
	res[0] = arr[0];
	for (i = 1;i < num;i++)
	{
		res[i] = arr[i];
		for (j = 0;j < i;j++)
		{
			if (arr[j]<arr[i] && res[j] + arr[i]>res[i])
			{
				res[i] = res[j] + arr[i];
			}
		}
	}
	maxim = res[0];
	for (i = 1;i < num;i++)
	{
		maxim = max(maxim, res[i]);
	}
	printf("%lld", maxim);
	return 0;
}
