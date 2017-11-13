/*Using Kruskal's Algorithm*/

#include <stdio.h>
#include <limits.h>

int nodeCount;
int MC;
int acceptedWeight;

int findMinEdge(int M, int weight[M]){
	int min = weight[0];
	int index = 0;
	for (int i = 1; i < M; ++i)
	{
		if (weight[i] < min)
		{
			index = i;
			min = weight[i];
		}
	}
	acceptedWeight = weight[index];
	weight[index] = INT_MAX; 
	return index;
}


int checkCycle(int pre, int post, int N, int nodes[N]){
	if (nodes[pre] == nodes[post])
	{
		return 0;
	}
	else{
		
		for (int i = 0; i < N; ++i)
		{
			if (nodes[i] == nodes[post])
			{
				nodes[i] = nodes[pre];
			}
		}
		nodes[post] = nodes[pre];
		return 1;
	}
}



void addNodes(int M, int pre[M], int post[M], int weight[M], int N, int nodes[N]){
	int index;

	do{
		index = findMinEdge(M,weight);

	}while(checkCycle(pre[index],post[index],N,nodes)!=1);
	MC = MC+acceptedWeight;

}

int main()
{
	int N, M, R;
	scanf("%d",&N);
	scanf("%d",&M);
	int pre[M],post[M],weight[M];
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d %d",&pre[i], &post[i], &weight[i]);
	}
	scanf("%d", &R);
	int compulsory[R];
	for (int i = 0; i < R; ++i)
	{
		scanf("%d", &compulsory[i]);
	}

	int nodes[N];
	MC = 0;
	
	nodeCount = 0;
	for (int i = 0; i < N; ++i)
	{
		nodes[i] = i;
	}

	for (int i = 0; i < R; ++i)
	{
		MC = MC + weight[compulsory[i]];
		weight[compulsory[i]] = INT_MAX;
		int x = checkCycle(pre[compulsory[i]],post[compulsory[i]],N,nodes);
	}

	for (int i = 0; i < N-1-R; ++i)
	{
		addNodes(M,pre,post,weight,N,nodes);
	}

	printf("%d\n", MC);
	return 0;
}