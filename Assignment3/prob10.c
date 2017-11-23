#include <stdio.h>
int counter = 0;
int findpath(int beg, int final, int N,int M, int pre[M], int post[M], int visited[N], int path[]){
	if (beg == final)
	{
		path[counter] =  beg;
		counter++;
		return 1;
	}
	for (int i = 0; i < M; ++i)
	{
		if (pre[i] == beg && visited[post[i]] == 0)
		{
			visited[post[i]] = 1;
			if(findpath(post[i],final,N,M,pre,post,visited,path) == 1){
				path[counter] = beg;
				counter++;
				return 1;
			}
		}
		if (post[i] == beg && visited[pre[i]] == 0)
		{
			visited[pre[i]] = 1;
			if(findpath(pre[i],final,N,M,pre,post,visited,path) == 1){
				path[counter] = beg;
				counter++;
				return 1;
			}
		}
	}
	counter--;
	return 0;
}

int main()
{
	int N,M;
	scanf("%d",&N);
	scanf("%d",&M);
	int pre[M];
	int post[M];
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &pre[i], &post[i]);
	}
	int beg,final;
	scanf("%d",&beg);
	scanf("%d",&final);
	int visited[N];
	int path[100];
	for (int i = 0; i < N; ++i)
	{
		visited[i] = 0;
	}
	visited[beg] = 1;
	if(findpath(beg,final,N,M,pre,post,visited,path)){
		for (int i = counter-1; i >= 0; i--)
		{
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	else{
		printf("No path exists\n");
	}
	return 0;
}