#include <stdio.h>
int N;
int isTransitive(int matrix[N][N])
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (matrix[i][j])
        {
          for (int k = 0; k < N; k++)
          {
            if (matrix[j][k] && !matrix[i][k])
            {
              return 0;
            }
          }
        }
      }
    }
    return 1;
  }

int isreflexive(int matrix[N][N]){
	for (int i = 0; i < N; i++)
	{
		if(matrix[i][i] == 0){
			return 0;
		}
	}
	return 1;
}

int isantisymmetric(int matrix[N][N]){
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if(i!=j && matrix[i][j]==1 && matrix[j][i]==1){
				return 0;
			}
		}
	}
	return 1;
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
	int trasitive = isTransitive(matrix);
	int reflexive = isreflexive(matrix);
	int antisymmetric = isantisymmetric(matrix);
	if(reflexive && trasitive && antisymmetric){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
