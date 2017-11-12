#include <stdio.h>
int main()
{
	int count1=0, count0=0;
	int N;
	scanf("%d", &N);
	while(N!=0 && N!=1){
		if (N%2 == 0)
		{
			N = N/2;
			count0++;
		}
		else{
			N = (N-1)/2;
			count1++;
		}

	}
	if(N==1){
		count1++;
	}
	else if(N==0){
		count0++;
	}
	if (count0 == count1)
	{
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}