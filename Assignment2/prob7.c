#include <stdio.h>

int bubbleSort(int N, int pre[N], int post[N], int weights[N]){
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = 0; j < N-1-i; ++j)
		{
			if (weights[j] > weights[j+1])
			{
				int temp = weights[j];
				weights[j] = weights[j+1];
				weights[j+1] = temp;
				temp = pre[j];
				pre[j] = pre[j+1];
				pre[j+1] = temp;
				temp = post[j];
				post[j] = post[j+1];
				post[j+1] = temp;
			}
		}
	}
}

void quickUnion(int N, int nodes[N], int pre, int post){
	for (int i = 0; i < N; ++i)
	{
		if (nodes[i] == nodes[post])
		{
			nodes[i] = nodes[pre];
		}
	}
	nodes[post] = nodes[pre];
}

int main()
{
	int N;
	scanf("%d",&N);
	int xcor[N],ycor[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &xcor[i], &ycor[i]);
	}
	int K;
	scanf("%d", &K);
	int edges = (N*(N-1))/2;
	int pre[edges], post[edges], weights[edges];
	int x = 0;
	for (int j = 0; j < N; ++j)
	{
		for (int k = j; k < N; ++k)
		{
			if (j!=k)
			{
				pre[x] = j; 
				post[x] = k;
				weights[x] = ((xcor[j] - xcor[k])*(xcor[j] - xcor[k])) + ((ycor[j] - ycor[k])*(ycor[j] - ycor[k]));
				x++; 
			}
		}		
	}
	bubbleSort(edges, pre, post, weights);
	int nodes[N];
	for (int i = 0; i < N; ++i)
	{
		nodes[i] = i;
	}
	for (int i = 0; i < N-K; ++i)
	{
		quickUnion(N,nodes,pre[i],post[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (nodes[j] == i)
			{
				printf("%d ", j);
			}
		}
		printf("\n");
	}
	return 0;
}