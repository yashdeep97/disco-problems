/*
an edge is present between 2 nos. only if their quotient a prime number
ie if a--b then a/b is prime
*/


#include <stdio.h>

int isPrime(int n){
	if(n == 0 || n == 1){
		return 0;
	}
	for(int i =2; i * i <= n; i++)
	{
		if(n % i == 0){
			return 0;
		}
	}
	return 1;
}


int main(){
	int n;
	scanf("%d", &n);
	int edges = 0;
	int divisors[n];
	for (int i = 0; i < n; ++i)
	{
			divisors[i] = 0;
	}

	int i=1,j=0;
	while(i < n+1)
	{
		if(n%i == 0)
		{
			divisors[j] = i;
			j++;
		}
		i++;
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	printf("%d ", divisors[i]);
	// }

	for (int i = 0; i < n && divisors[i] != 0 ; ++i)
	{
		for (int j = i+1; j < n && divisors[j] != 0; ++j)
		{
			if (i == j)
			{
				continue;
			}
			else{
				if (isPrime((int)(divisors[j]/divisors[i])) && divisors[j]%divisors[i] == 0)
				{
					edges++;
				}
			}
		}
	}
	printf("%d\n", edges);

	return 0;
}