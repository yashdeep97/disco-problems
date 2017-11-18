#include <stdio.h>

int main()
{
	int N,M;
	scanf("%d",&N);
	scanf("%d",&M);
	int pre[M],post[M];
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d",&pre[i],&post[i]);
	}
	double matrix[N][N];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 0; i < M; ++i)
	{
		matrix[pre[i]][post[i]] = 1;
	}

	for (int i = 0; i < N; ++i)
	{
		int sum = 0;
		for (int j = 0; j < N; ++j)
		{
			sum = sum + matrix[i][j];
		}
		if (sum == 0)
		{
			for (int j = 0; j < N; ++j)
			{
				matrix[i][j] = (double)1/(double)N;
			}
		}
		else{
			for (int j = 0; j < N; ++j)
			{
				matrix[i][j] = matrix[i][j]/sum;
			}	
		}
	}


	double prob[N];
	prob[0] = 1;
	for (int i = 1; i < N; ++i)
	{
		prob[i] = 0;
	}
	int x = 0;
	double final[N];
	while(x!=10){

		for (int i = 0; i < N; ++i)
		{
			double sum = 0;
			for (int j = 0; j < N; ++j)
			{
				sum = sum + prob[j]*matrix[j][i];
			}
			final[i] = sum;
		}
		for (int i = 0; i < N; ++i)
		{
			prob[i] = final[i];
		}
		
		x++;
	}
	for (int i = 0; i < N; ++i)
	{
		printf("%lf ", prob[i]);
	}
	// for (int i = 0; i < N; ++i)
	// {
	// 	for (int j = 0; j < N; ++j)
	// 	{
	// 		printf("%lf ", matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }
	return 0;
}