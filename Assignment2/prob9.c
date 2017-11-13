#include <stdio.h>

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
	int degreeCount[N];
	for (int i = 0; i < N; ++i)
	{
		degreeCount[i] = 0;
	}
	for (int i = 0; i < M; ++i)
	{
		degreeCount[pre[i]]++;
		degreeCount[post[i]]++;
	}
	int oddCount = 0;
	for (int i = 0; i < N; ++i)
	{
		if (degreeCount[i]%2 == 1)
		{
			oddCount++;
		}
	}
	if (oddCount==2 || oddCount==0)
	{
		printf("Yes\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}