#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int dimensions[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &dimensions[i]);
	}
	int volume = 1;
	for (int i = 0; i < n; ++i)
	{
		volume *= dimensions[i];
	}
	int count = 0;
	while(volume%2 == 0){
		volume /= 2;
		count++;
	}
	if (count%2 == 0)
	{
		printf("Galactus\n");
	}
	else{
		printf("Uatu\n");
	}
	return 0;
}