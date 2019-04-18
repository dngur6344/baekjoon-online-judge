#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int M, N;
	int sum = 0, min;
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 1;i*i < N;i++)
	{
	}
	if (i*i > M)
	{
		printf("-1\n");
		return 0;
	}
	min = i * i;
	for (j = i;j*j <=M;j++)
	{
		sum += j * j;
	}
	printf("%d\n", sum);
	printf("%d\n", min);
	return 0;
}
