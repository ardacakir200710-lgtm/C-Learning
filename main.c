#include <stdio.h>

#define LEN 10

void selection1(int* arr);
void selection2(int* arr);

int main(void)
{
	int arr[LEN] = { 0 };
	char ch;

	printf("Enter the numbers to be sorted:\n");

	for (int i=0; i<LEN; i++){
		scanf("%d",&arr[i]);
	}

	printf("(A)scending or (D)escendig? ");
	scanf(" %c",&ch);

	if(ch == 'D')
		selection1(arr);
	else if(ch == 'A')
		selection2(arr);
	else
		return -1;
	
	
	printf("\nNumbers Sorted:\n");

	
	for (int i=0; i<LEN; i++){
		printf("%d ",arr[i]);
	}
		
	printf("\n");
	return 0;		
}

void selection1(int* arr)
{
	int start_idx = 0;
	int min_idx = 0;
	int temp;
	
	for (start_idx = 0; start_idx < LEN; start_idx++)
	{
		min_idx = start_idx;
		
		// finding the smallest
		for(int i = start_idx; i < LEN; i++){
			if(arr[i] < arr[min_idx]){
				min_idx = i;
			}
		}

		temp = arr[start_idx];
		arr[start_idx] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

void selection2(int* arr)
{
	int max_idx;
	int temp;
	
	for (int i=0; i<LEN; i++){

		max_idx = i;

		for(int j = i; j < LEN; j++){
			if(arr[j] > arr[max_idx]){
				max_idx = j;
			}
		}

		temp = arr[i];
		arr[i] = arr[max_idx];
		arr[max_idx] = temp;
		
	}
}
