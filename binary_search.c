/*
Author: Arda Muhammed Çakır
This code is just for my individual practice and learning algorithms.
*/

#include <stdio.h>
#include <stdbool.h>

int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

bool binarySearch(int key,int size);

int main(void)
{
    int arr_size = sizeof(arr) / sizeof(int);
    int key = 7;

    if(binarySearch(key, arr_size))
        printf("Number found!\n");
    else
        printf("Number not found..\n");
    

    return 0;
}

bool binarySearch(int key, int size){
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


