#include <stdio.h>

void matrixMul(int N, int a[N][N], int b[N][N], int ans[N][N]){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int x = 0;
			for (int k = 0; k < N; ++k)
			{
				x += a[i][k]*b[k][j];
			}
			ans[i][j] = x;
		}
	}
}

int main()
{
	int N,E;
	scanf("%d",&N);
	scanf("%d",&E);
	int pre;
	int post;
	int matrix[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d", &pre, &post);
		matrix[pre][post] = 1;
		matrix[post][pre] = 1;
	}
	int square[N][N];
	int cube[N][N];
	matrixMul(N,matrix,matrix,square);
	matrixMul(N,square,matrix,cube);
	int trace = 0;
	for (int i = 0; i < N; ++i)
	{
		trace += cube[i][i];
	}
	printf("%d\n", trace/6);

	return 0;
}