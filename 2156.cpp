#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int num, i,max=0;
	int arr[10000];
	int res[10000];
	scanf("%d", &num);
	for (i = 0;i < num;i++)
	{
		scanf("%d", &arr[i]);
	}
	if (num == 1)
	{
		printf("%d\n", arr[0]);
		return 0;
	}
	else if (num == 2)
	{
		printf("%d\n", arr[0] + arr[1]);
		return 0;
	}
	res[0] = arr[0];
	res[1] = arr[0] + arr[1];
	if (arr[0] + arr[2] > arr[1] + arr[2])
	{
		res[2] = arr[0] + arr[2];
	}
	else
	{
		res[2] = arr[1] + arr[2];
	}
	if (res[2] < arr[0] + arr[1])
		res[2] = arr[0] + arr[1];
	for (i = 3;i < num;i++)
	{
		if (res[i - 3] + arr[i - 1] + arr[i] > res[i - 2] + arr[i])
		{
			res[i] = res[i - 3] + arr[i - 1] + arr[i];
		}
		else
		{
			res[i] = res[i - 2] + arr[i];
		}
		if (res[i] < res[i - 1])
		{
			res[i] = res[i - 1];
		}
	}
	/*if (res[num - 1] > res[num - 2])
	{
		printf("%d", res[num - 1]);
	}
	else
	{
		printf("%d", res[num - 2]);
	}*/
	/*for (i = 0;i < num;i++)
	{
		if (res[i] > max)
			max = res[i];
	}*/
	printf("%d\n", res[num-1]);
	return 0;
}
