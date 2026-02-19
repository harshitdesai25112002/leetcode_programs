#include<stdio.h>
#include<stdbool.h>

int issorted(int* nums, int numsSize) {
    for(int i=0; i<numsSize-1; i++)
    {
        if(nums[i]>nums[i+1])
        {
            return -1; //Returns when the array is not sorted.
        }
        else{
            continue;
        }
            
    }
    return 1; //Returns when the array is sorted after full scanning.
}
int main() {
    int arr[] = {1, 2, 3, 4, 8, 9, 10}; 
    int size = 7; // Size of the array
    int sorted = issorted(arr, size);
    if (sorted==-1 ) {
        printf("Array is not sorted.\n");
        //printf("At index %d",i);
    }
    else {
        printf("Array is sorted.\n");
    }
    return 0;
}