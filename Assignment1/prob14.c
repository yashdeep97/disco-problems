#include <stdio.h>

int factorial(int num){
	if(num == 0)
		return 1;
	else
		return num*factorial(num-1);
}

int combination(int n, int r){
	return (factorial(n)/(factorial(n-r)*factorial(r)));
}

int main()
{
	int n;
	scanf("%d", &n);
	int edges = 0;
	for (int i = 0; i < n; ++i)
		{
			edges += (n-i)*combination(n,i);
		}	
		printf("%d\n", edges);
	return 0;
}