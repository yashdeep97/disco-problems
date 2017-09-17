#include <stdio.h>
int array_length(int a[]);
int main()
{
	int groupsCount;
	scanf("%d", &groupsCount);
	int groups[groupsCount][100];
	for (int i = 0; i < groupsCount; i++)
	{
		int elementCount;
		scanf("%d", &elementCount);
		int elements[elementCount];
		groups[i] = elements;
		for (int j = 0; j < elementCount; j++)
		{
			scanf("%d",groups[i] + j);
			
		}
	}

	// for (int i = 0; i < groupsCount; i++)
	// {
	// 	int newgroup;
	// 	int length = 3;
	// 	// printf("%d\n", length);
	// 	for (int j = 0; j < 3; j++)
	// 	{
	// 		// newgroup = *(groups[i]);

	// 		// for (int k = 0; i < array_length(groups[i]); k++)
	// 		// {
	// 		// 	if(k != j){
	// 		// 		printf(" %d ", *(groups[i] + j));
	// 		// 	}
	// 		// }
	// 		printf("\n %d",*(groups[0] + j));
	// 		// printf("*************************\n");
	// 	}
		
	// }
	return 0;
}
