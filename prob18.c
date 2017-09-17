#include <stdio.h>

void getSubset(int array[], int a, int size, int choose){
	for (int i = 1; i < choose; i++)
	{
		printf(" %d", array[a+i]);
	}

}

int main()
{
	int N,K;
	scanf("%d", &N);
	int gadgets[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&gadgets[i]);	
	}
	scanf("%d", &K);
	for (int i = 0; i <= (N-K); i++)
	{
		printf("\n%d", gadgets[i]);
		getSubset(gadgets, i, N, K);
	}
	printf("\n");
	
	return 0;
}
