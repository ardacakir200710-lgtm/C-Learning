/*
Author: Arda Muhammed Çakır
This code is just for my individual practice and learning algorithms.
*/

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int key,int size,int *arr);

int main(void)
{
    int *arr_ptr = NULL;
    int arr_size = 0;
    int key;
    int n;
    char ch;

    printf("Enter the array: ");

    while((ch = getchar()) != '\n')
    {
        scanf("%d",&n);
        arr_ptr = (int* )realloc(arr_ptr,(arr_size + 1) * sizeof(int)); 
        arr_ptr[arr_size++] = n;
    }

    printf("Enter the key to be searched:");
    scanf("%d",&key);

    if(binarySearch(key, arr_size, arr_ptr))
        printf("Number found!\n");
    else
        printf("Number not found..\n");
    
    free(arr_ptr);
    arr_ptr = NULL;

    return 0;
}

int binarySearch(int key, int size, int *arr){
    int idx_high = size - 1;
    int idx_low = 0;
    int idx_mid;

    while(idx_low <= idx_high)
    {
        idx_mid = (idx_high + idx_low) / 2;
        if(key == arr[idx_mid])
        {
            return 1;            
        }
        else{
            if(key > arr[idx_mid])
            {
                idx_low = idx_mid + 1;
            }
            else{
                idx_high = idx_mid - 1;
            }
        }
    }

    return 0;       

}


