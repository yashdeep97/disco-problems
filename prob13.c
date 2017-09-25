#include <stdio.h>
int N;
void completeTransitive(int matrix[N][N])
  {
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < N; j++)
      {
        if (matrix[i][j]*matrix[j][i] == 1)
        {
        	matrix[i][i] = 1;
        }
      }
    }
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
	completeTransitive(matrix);
	int reflexive = isreflexive(matrix);

	if(reflexive){
		printf("Reflexive\n");
	}
	else{
		printf("Not Reflexive\n");
	}
	return 0;
}
