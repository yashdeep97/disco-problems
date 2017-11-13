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
	int flagpre = 0;
	int flagpost = 0;
	for (int i = 0; i < N; ++i)
	{
		if (nodes[i] == pre)
		{
			flagpre++;
			break;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (nodes[i] == post)
		{
			flagpost++;
			break;
		}
	}
	if ( flagpre == 1 && flagpost == 1)
	{
		return 0;
	}
	else if(flagpre == 1 && flagpost == 0)
	{
		nodes[nodeCount] = post;
		nodeCount++;

		return 1;
	}
	else if (flagpre == 0 && flagpost == 1)
	{	
		nodes[nodeCount] = pre;
		nodeCount++;
		return 1;
	}
	else{
		nodes[nodeCount] = pre;
		nodeCount++;
		nodes[nodeCount] = post;
		nodeCount++;
		return 1;
	}
}


void addNodes(int M, int pre[M], int post[M], int weight[M], int N, int nodes[N]){
	int index;

	do{
		index = findMinEdge(M,weight);

	}while(checkCycle(pre[index],post[index],N,nodes)!=1);
	MC = MC*acceptedWeight;

}

int main()
{
	int N, M;
	scanf("%d",&N);
	scanf("%d",&M);
	int pre[M],post[M],weight[M];
	for (int i = 0; i < M; ++i)
		{
			scanf("%d %d %d",&pre[i], &post[i], &weight[i]);
		}
	int nodes[N];
	MC = 1;
	nodeCount = 0;
	for (int i = 0; i < N; ++i)
	{
		nodes[i] = INT_MAX;
	}
	for (int i = 0; i < N-1; ++i)
	{
		addNodes(M,pre,post,weight,N,nodes);
	}

	printf("%d\n", MC);
	return 0;
}