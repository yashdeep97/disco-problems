#include <stdio.h>
#include <stdlib.h>
int N;
int temp[50];
int head=0;
void findDependencies(int row, int matrix[N][N]){
	for(int col = 0; col < N; col++){
		if(matrix[row][col] == 1){
			// printf("%d ", col);
			temp[head] = col;
			head++;
			matrix[row][col] = 0;
			findDependencies(col, matrix);
		}
	}
	return;
}

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
	int K;
	scanf("%d",&N);
	scanf("%d",&K);
	int pre[K];
	int post[K];
	int matrix[N][N];
	for (int i = 0; i < K; i++)
	{
		scanf("%d %d", &pre[i], &post[i]);
		// printf("%d %d\n", pre[i], post[i]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = 0;
		}
	}
	printf("\n");
	for (int i = 0; i < K; i++)
	{
		matrix[pre[i]][post[i]] = 1;
	}

	int col,row;
	for (row = 0; row < N; row++)
	{
		int test[N][N];
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				test[i][j] = matrix[i][j];
			}
		}
		for (int i = 0; i < 100; ++i)
		{
			temp[i] = -1;
		}
		head =0;
		findDependencies(row, test);
		
		int i = 0;
		while(temp[i] != -1){
			i++;
		}
		int len = i;
		int array[len];
		for (int i = 0; i < len; ++i)
		{
			array[i] = temp[i];
		}
		qsort(array, len, sizeof(int), cmpfunc);

		for (int i = 0; i < len; ++i)
		{
			if(array[i] == row || array[i] == array[i+1]){
				array[i] = -1;
			}
		}
		for (int i = 0; i < len-1; i++)
		{
			if(array[i] == -1){
				for (int j = i; j < len-1; j++)
				{
					array[j] = array[j+1];
				}
				len = len-1;
			}
		}
		if(array[len-1] == -1){
			len--;
		}
		
		for (int i = 0; i < len; ++i)
		{
			printf("%d ", array[i]);
		}
		if(len == 0){
			printf("-");
		}
		printf("\n");
	}
	return 0;
}
