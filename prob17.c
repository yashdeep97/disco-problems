/*
Solved using bitstring manipulation
*/

#include <stdio.h>

void printset(int n, int all[n], int number){
	for (int i = 0; i < n; ++i)
	{
		if ((number & (1<<i)) != 0)
		{
			printf("%d ", all[i]);
		}
	}
	printf("\n");
}

int findPos(int n, int all[n], int num){
	for (int i = 0; i < n; ++i)
	{
		if (all[i] == num)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int n;
	scanf("%d", &n);
	int all[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &all[i]);
	}

	int maxbinary = (1<<n) - 1;
	int k;
	scanf("%d", &k);
	int curSkills = 0;
	for (int i = 0; i < k; ++i)
	{	
		int num;
		scanf("%d", &num);
		int index = findPos(n, all, num);
		curSkills |= (1<<index);
	}
	int q;
	scanf("%d", &q);
	int req = 0;
	for (int i = 0; i < q; ++i)
	{
		int temp;
		scanf("%d", &temp);
		int index = findPos(n, all, temp);
		req |= (1<<index);
	}
	for (int i = 0; i < maxbinary; ++i)
	{
		if ((curSkills | i) == req)
		{
			printset(n, all, i);
		}
	}

	return 0;
}