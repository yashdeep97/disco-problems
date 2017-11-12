#include <stdio.h>

int findnum(int n, int array[n], int num){
	for (int i = 0; i < n; ++i)
	{
		if (array[i] == num)
		{
			return 1;
		}
	}
	return 0;
}

int checkReturn(int n, int passfactor[n], int current){
	int array[n];
	for (int i = 0; i < n; ++i)
	{
		array[i] = -1;
	}
	int head = 0;
	int pos = current;
	while(1){
		int next = (pos + passfactor[pos])%n;
		if(next == current){
			return 1;
		}
		else{
			if (findnum(n, array, next) == 1)
			{
				return 0;
			}
			array[head] = next;
			head++;
			pos = next;
		}
	}
}

int main(){

	int n;
	scanf("%d", &n);
	int passfactor[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &passfactor[i]);
	}
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (checkReturn(n, passfactor, i) == 1)
		{
			count++;
		}
	}
	printf("%d\n", count);

	return 0;
}