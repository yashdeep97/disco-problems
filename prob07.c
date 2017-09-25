#include <stdio.h>

int isCoprime(int a, int b){
	int x,y;
	if (a==1 || b==1)
	{
		return 1;
	}
	if(a>b){
		x=b;
		y=a;
	}
	else{
		x=a;
		y=b;
	}
	for (int i = 2; i <= x; ++i)
	{
		if(y%i == 0 && x%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){

	int p,q;
	scanf("%d %d", &p,&q);
	int numStart = p+q-1;
	int rank = 0;
	for (int i = 1; i <= numStart; ++i)
	{
		if (i%2 == 1)
		{
			int num = i;
			int denom = 1;
			do{
				if (isCoprime(num,denom))
				{
					rank++;
					if (num==p && denom==q)
					{
						printf("%d\n", rank);
						return 0;
					}
				}
				num--;
				denom++;
			}while(num >= 1);

		}
		else{
			int num = 1;
			int denom = i;
			do{
				if (isCoprime(num,denom))
				{
					rank++;
					if (num==p && denom==q)
					{
						printf("%d\n", rank);
						return 0;
					}
				}
				num++;
				denom--;
			}while(denom >= 1);
		}
	}
	printf("%d\n", rank);
	return 0;
}