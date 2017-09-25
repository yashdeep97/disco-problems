#include <stdio.h>
int main()
{
	int e, m;
	scanf("%d %d", &e, &m);

	int matrix[e+1][e+1];
	
	for (int i = 0; i <= e; ++i)
	{
		for (int j = 0; j <= e; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	for (int j = 0; j <= e; ++j)
	{
		matrix[j][0] = 1;
	}

	for(int i = m; i <= e; i++)
	{
		for(int j = 1; j <= e; j++)
		{
			if(j-i >= 0){
				matrix[i][j] = matrix[i-1][j] + matrix[i][j-i];
			}
			else{
				matrix[i][j] = matrix[i-1][j];
			}
		}
	}


	// for (int i = 0; i <= e; ++i)
	// {
	// 	for (int j = 0; j <= e; ++j)
	// 	{
	// 		printf("%d ", matrix[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("%d\n", matrix[e][e]);
	
	return 0;
}