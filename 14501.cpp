#include<stdio.h>
#include<stdlib.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
int main(void)
{
	int num;
	int time[16];
	int arr[16];
	int res[16] = { 0, };
	int i, j;
	scanf("%d", &num);
	for (i = 1;i <= num;i++)
	{
		scanf("%d %d", &time[i], &arr[i]);
	}
	for (i = 1;i <= num;i++)
	{
		res[i] = res[i - 1];
		for (j = 1;j < i;j++)
		{
			if (j + time[j] - 1 == i)
			{
				if (res[i] < res[j-1] + arr[j])
				{
					res[i] = res[j - 1] + arr[j];
				}
			}
		}
		if (j + time[j] - 1 == i)
		{
			if(res[i]<res[i-1]+arr[i])
				res[i] = res[i - 1] + arr[i];
		}
	}
	j = res[0];
	for (i = 1;i <= num;i++)
	{
		j = max(j, res[i]);
	}
	printf("%d", j);
	return 0;
}
