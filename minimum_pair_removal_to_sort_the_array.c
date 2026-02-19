/*
    Given an array nums, you can perform the following operation any number of times:

Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.

An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

Example 1:

Input: nums = [5,2,3,1]

Output: 2

Explanation:

The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:

Input: nums = [1,2,2]

Output: 0

Explanation:

The array nums is already sorted.

 

Constraints:

1 <= nums.length <= 50
-1000 <= nums[i] <= 1000
*/

#include<stdio.h>

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

int minimumPairRemoval(int* nums, int numsSize) {
    int i;
    int sum;
    int sorted;
    int operation =0;

    while(issorted(nums, numsSize)==-1) //Here, We Check whether the array is sorted or not.
    {
        int index=0;    //To store the index of the pair which has minimum sum.
        int minSum = nums[0] + nums[1]; //Here, we intialize the minimum sum of first pair.
        for(i=1; i<numsSize-1;i++)  //Here, i=1 because we have already made sum of first pair.
        {
            sum = nums[i] + nums[i+1]; //Here, we calculate the sum.
            if(sum<minSum) //Here, we check for the minimum sum. 
            {
                minSum = sum; //Here, we are updating the sum.
                index = i; //Here, we are updating the index of the pair.
            }
        }

        nums[index] = minSum; //Here, we are replacing the first value of pair with minimum sum.
        for(int j=index+1; j<numsSize-1; j++) //Here, we are shifting the elements to left after replacing the pair with minimum sum.
        {
            nums[j]=nums[j+1];
        }

        numsSize--; //Here, we are reducing the size of the array after removing the pair.
        operation++; //Here, we are counting the number of operations needed to make the array non-decreasing.
    }

    return operation; //Here, we are returning the number of operations. Which is our main aim.
}

int main()
{
    int size ; // Size of the array
    
    printf("Enter the the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size]; // Array to hold the input numbers
    printf("Enter the elements of the array: \n");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int operations = minimumPairRemoval(arr, size);
    printf("Minimum number of operations needed to make the array non-decreasing: %d\n", operations);


    /*printf("The modified array is: \n");
    for(int i=0; i<size-operations; i++)
    {
        printf("%d ", arr[i]);
    }*/
    return 0;
}