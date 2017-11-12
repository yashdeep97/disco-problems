#include <stdio.h>
// divisor = col + 1
//dividend = row + 1

int divisorTuples(int len, int array[len], int n, int matrix[n][n]){
	int count = 0;
	// printf("len: %d\n", len);
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			if (array[i]!=array[j] && matrix[array[i]-1][array[j]-1] == 1)
			{
				count++;
				// printf("%d %d, ", array[i],array[j]);
			}
		}
	}
	return count;
}

int main(){
	int n;
	scanf("%d", &n);
	int matrix[n][n];
	int input[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &input[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if((i+1)%(j+1) == 0){
				matrix[i][j] = 1;
			}
			else{
				matrix[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	int maxbinary = (1<<n)-1;
	for (int i = 0; i <= maxbinary; ++i)
	{
		int array[50];
		for (int k = 0; k < 50; ++k)
		{
			array[i] = -1;
		}
		int head = 0;
		for (int j = 0; j < n; ++j)
		{
			if ((i & (1<<j)) != 0)
			{
				array[head] = input[j];
				head++;
			}
		}
		// int  m = 0;
		// 	while(array[m] != -1){
		// 		printf("%d ", array[m]);
		// 		m++;
		// 	}
		if (divisorTuples(head, array, n, matrix)%2 == head%2)
		{
			
			for(int m = 0; m < head; m++)
			{
				printf("%d ", array[m]);
			}
			printf("\n");
		}
		// printf("%d", divisorTuples(head, array, n, matrix));
		
	}

	return 0;
}