#include<stdio.h>
#include<stdlib.h>
int compare(void *first, void *second)
{
	if (*(int*)first > *(int*)second)
		return 1;
	else if (*(int*)first < *(int*)second)
		return -1;
	else
		return 0;
}
int main(void)
{
	int num;
	int *arr;
	int i, j;
	scanf("%d", &num);
	arr = (int*)malloc(sizeof(int)*num);
	for (i = 0;i < num;i++)
	{
		scanf("%d", &arr[i]);
	}
	qsort(arr, num, sizeof(int), compare);
	for (i = 0;i < num;i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}
