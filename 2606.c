#include<stdio.h>
#include<stdlib.h>
void search(int arr[101][101], int check[101],int index1, int num);
int sum = 0;
int main(void)
{
	int num, ssang;
	int input1, input2;
	int arr[101][101];
	int check[101] = { 0, };
	int i, j;
	scanf("%d", &num);
	scanf("%d", &ssang);
	for (i = 1;i <= num;i++)
	{
		for (j = 1;j <= num;j++)
		{
			arr[i][j] = 0;
		}
	}
	for (i = 0;i < ssang;i++)
	{
		scanf("%d %d", &input1, &input2);
		arr[input1][input2] = 1;
		arr[input2][input1] = 1;
	}
	for (j = 2;j <= num;j++)
	{
		if (arr[1][j] == 1)
		{
			if (check[j] == 0)
			{
				sum += 1;
				check[j] = 1;
				search(arr, check, j, num);
			}
		}
	}
	if (sum != 0)sum = sum - 1;
	printf("%d\n", sum);
	return 0;
}
void search(int arr[101][101], int check[101],int index1, int num)
{
	int i, j;
	for (i = 1;i <= num;i++)
	{
		if (arr[index1][i] == 1)
		{
			if (check[i] == 0)
			{
				sum += 1;
				check[i] = 1;
				search(arr, check, i, num);
			}

		}
	}
}
