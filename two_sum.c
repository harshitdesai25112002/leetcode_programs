/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


/*
struct result{
        int x;
        int y;
    }; 
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int sum;
    int i, j;
    for (i=0; i<numsSize; i++)
    {
        for (j=i+1; j<numsSize; j++)
        {
            sum = nums[i] + nums[j];
            if(sum == target)
            {
                struct result r;
                r.x = i;
                r.y = j;

                return r;
            }
            else
            {
                continue;
            }
        }
    }
}*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include<stdlib.h>
#include<stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int sum;
    int i, j;
    int* solution = malloc(2 * sizeof(int)); //Here we allocate the memory for solution array which will store the indices of the two numbers that add up to target.
    for (i=0; i<numsSize; i++) //Here, we iterate through the array to find the two numbers that add up to target.
    {
        for (j=i+1; j<numsSize; j++) //Here, we start j from i+1 to avoid using the same element twice and to ensure that we are checking pairs of numbers.
        {
            sum = nums[i] + nums[j]; //Here, we calculate the sum of the two numbers at indices i and j.
            if(sum == target) //Here, we check if the sum is equal to the target.
            {
                solution[0] = i; //If the sum is equal to the target, we store the indicex i in the solution array.
                solution[1] = j; //Here, we store the index j in the solution array.
                *returnSize = 2; //Here, we set the returnSize to 2 because we are returning two indices in the solution array.
                return solution; //Here, we return the solution array which contains the indices of the two numbers that add up to target.
            }
        }
    }
    *returnSize =0;
    return NULL;
}

int main()
{
    int nums[] = {2,7,11,15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, sizeof(nums)/sizeof(nums[0]), target, &returnSize);
    if(result != NULL)
    {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result); // Here, we free the allocated memory for the solution array after using it to avoid memory leaks.
    }
    else
    {
        printf("No solution found.\n");
    }
    return 0;
}