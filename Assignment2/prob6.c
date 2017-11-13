#include <stdio.h>

int findpath(int beg, int final, int M, int pre[M], int post[M], int visited[M]){
	if (beg == final)
	{
		return 1;
	}
	for (int i = 0; i < M; ++i)
	{
		if (pre[i] == beg && visited[i] == 0)
		{
			visited[i] = 1;
			if(findpath(post[i],final,M,pre,post,visited) == 1){
				return 1;
			}
		}
		if (post[i] == beg && visited[i] == 0)
		{
			visited[i] = 1;
			if(findpath(pre[i],final,M,pre,post,visited) == 1){
				return 1;
			}
		}
	}
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
	int visited[M];
	for (int i = 0; i < M; ++i)
	{
		visited[i] = 0;
	}
	if(findpath(beg,final,M,pre,post,visited)){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}