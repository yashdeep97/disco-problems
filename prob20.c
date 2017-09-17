#include <stdio.h>

int power(int a, int b){
	int ans = a;
	for (int i = 0; i < (b-1); i++)
	{
		ans *= a;
		ans = ans%10;
	}
	return ans;
}

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	int m = power(M,N);
	printf("%d\n", m);
	return 0;
}
