#include <stdio.h>
void combinationUtil(int arr[], int data[], int start, int end, 
                     int index, int r);
 

void printCombination(int arr[], int n, int r)
{

    int data[r];
 

    combinationUtil(arr, data, 0, n-1, 0, r);
}
 

void combinationUtil(int arr[], int data[], int start, int end,
                     int index, int r)
{

    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }
 
    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}

int main()
{


    int N,K;
	scanf("%d", &N);
	int gadgets[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d",&gadgets[i]);
	}
	scanf("%d", &K);
	printCombination(gadgets, N, K);

	return 0;
}