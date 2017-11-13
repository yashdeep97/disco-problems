#include <stdio.h>

int counter = 0;

int allVisited(int N, int visited[N]){
	for (int i = 0; i < N; ++i)
	{
		if (visited[i] == 0)
		{
			return 0;
		}
	}
	return 1;
}

int checkCycle(int x, int M, int pre[M], int post[M]){
	for (int i = 0; i < M; ++i)
	{
		if (pre[i] == x && post[i] == 0)
		{
			return 1;
		}
		if (post[i] == x && pre[i] == 0)
		{
			return 1;
		}
	}
	return 0;
}

int findNextNode(int x, int N, int visited[N], int M, int pre[M], int post[M]){
	for (int i = 0; i < M; ++i)
	{
		if (pre[i] == x && visited[post[i]] == 0)
		{
			// printf("%d ", post[i]);
			visited[post[i]] = 1;
			if(findNextNode(post[i],N,visited,M,pre,post)){
				
				return 1;
			}			
				
		}
		if (post[i] == x && visited[pre[i]] == 0)
		{
			// printf("%d ", pre[i]);
			visited[pre[i]] = 1;
			if(findNextNode(pre[i],N,visited,M,pre,post)){
				
				return 1;
			}
		}
	}

	if (allVisited(N,visited) == 1)
	{
		counter++;
		return 1;
	}
	else{
		counter++;
		return 0;
	}
}


int main()
{
	int N, M;	
	scanf("%d",&N);
	scanf("%d",&M);
	int pre[M],post[M];
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d", &pre[i], &post[i]);
	}
	int visited[N];

	for (int i = 0; i < N; ++i)
	{
		visited[i] = 0;
	}
	visited[0] = 1;

	int x = findNextNode(0,N,visited,M,pre,post);

	printf("%d\n",counter);
	return 0;

}