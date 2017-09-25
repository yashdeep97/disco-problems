#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int greaterFlag = 0;
	int negativeCount = 0;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		if (temp>2 || temp<-2)
		{
			greaterFlag = 1;
		}
		if (temp < 0)
		{
			negativeCount++;
		}
		if (temp == 2 && negativeCount > 0)
		{
			greaterFlag = 1;
		}
		if (negativeCount >= 2)
		{
			greaterFlag = 1;
		}

	}

	if (greaterFlag == 1)
	{
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}