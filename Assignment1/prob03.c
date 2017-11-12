#include <stdio.h>
int N;
int checkDependencies(int j, int matrix[N][N]){
	int count = 0;
	for(int i = 0; i < N; i++){
		if (matrix[i][j] == 1)
		{
			count++;
		}
	}
	return count;
}

void checkDependents(int row, int matrix[N][N]){
	for(int col = 0; col < N; col++){
		if (matrix[row][col] == 1)
		{
			matrix[row][col] = 0;
			if(checkDependencies(col, matrix) == 0){
				printf("%d ", col);
				checkDependents(col, matrix);
			}
		}
	}
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
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 	{
	// 		printf("%d ", matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	int col,row;
	for (int col = 0; col < N; col++)
	{	
		int clearCol = checkDependencies(col, matrix);
		if(clearCol == 0){
			printf("%d ", col);
			row = col;
			break;
		}
	}
	checkDependents(row, matrix);
	printf("\n");
	return 0;
}
