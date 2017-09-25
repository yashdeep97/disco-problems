#include <stdio.h>

int countTruePrep(int n, int prepositions[n]){
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (prepositions[i])
		{
			count++;
		}
	}
	return count;
}


int main(){
	int n;
	scanf("%d", &n);
	int prepositions[n];
	for (int i = 0; i < n; ++i)
	{
		prepositions[i] = 0;
	}
	int k;
	scanf("%d", &k);
	int antecount[k];
	int expressons[k][50];
	for (int i = 0; i < k; ++i)
	{
		scanf("%d", &antecount[i]);
		antecount[i]++;
		for (int j = 0; j < 50; ++j)
		{
			expressons[i][j] = -1;
		}
		for (int j = 0; j < antecount[i]; ++j)
		{
			scanf("%d", &expressons[i][j]);
		}
	}

	int truthscount;
	scanf("%d", &truthscount);
	for (int i = 0; i < truthscount; ++i)
	{
		int temp;
		scanf("%d", &temp);
		prepositions[temp] = 1;
	}

	// for (int i = 0; i < antecount[0]; ++i)
	// {
	// 	printf("%d ", expressons[0][i]);
	// }
	// printf("\n");
	
	int pre = 0,current = 0;
	do{
		pre = current;
		// // check right side true values...
		// for (int i = 0; i < k; ++i)
		// {
		// 	if(prepositions[expressons[i][antecount[i]-1]] == 1){
		// 		for (int j = 0; j < antecount[i]; ++j)
		// 		{
		// 			prepositions[expressons[i][j]] = 1;
		// 		}
		// 	}
		// }

		// check left side
		for (int i = 0; i < k; ++i)
		{
			int flag = 1;
			for (int j = 0; j < antecount[i]-1; ++j)
			{
				if (prepositions[expressons[i][j]] == 1)
				{
					continue;
				}
				else{
					flag = 0;
					break;
				}

			}
			if(flag == 1){
				// printf("%d\n", expressons[i][antecount[i]-1]);
				prepositions[expressons[i][antecount[i]-1]] = 1;
			}
		}
		current = countTruePrep(n, prepositions);

	}while(current > pre);

	for (int i = 0; i < n; ++i)
	{
		if(prepositions[i] == 1){
			printf("%d ", i);
		}
	}
	printf("\n");

	return 0;
}