#include <stdio.h>


int main()
{
	int n;
	scanf("%d", &n);
	int k[n];
	int groups[n][50];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k[i]);
		for (int j = 0; j < k[i]; j++)
		{
			scanf("%d", &groups[i][j]);
		}
	}

	printf("\n");
	for (int i = 0; i < n; i++)
	{
		int bitString[k[i]];
		for (int j = 0; j < k[i]-1; j++)
		{
			bitString[j] = 0;
		}
		bitString[k[i]-1] = 1;
		int exit = 0;
		if(bitString[0] == 1){
			exit = 1;
		}

		while(exit == 0)
		{

			for (int a = 0; a < n; a++)
			{
				if(a != i){
					for (int b = 0; b < k[a]; b++)
					{
						printf("%d ", groups[a][b]);	
					}
					printf("\n");
				}
				else if(a == i){
					for (int c = 0; c < k[a]; c++)
					{
						if(bitString[c] == 0){
							printf("%d ", groups[a][c]);
						}
					}
					printf("\n");
					for (int d = 0; d < k[a]; d++)
					{
						if (bitString[d] == 1)
						{
							printf("%d ", groups[a][d]);
						}
					}
					printf("\n");
				}
			}
		
			int carry = 1;
			for (int e = (k[i]-1); e >= 0; e--)
			{	
				bitString[e] += carry;

				if(bitString[e] == 2){
					bitString[e] = 0;
					carry = 1;
				}
				else{
					carry = 0;
				}
			}


			if(bitString[0] == 1){
				exit = 1;
			}
			printf("*******************************\n");

		}

	}
	return 0;
}
