void moveZeroes(int* nums, int numsSize) {
    int read = 0;
    int write = 0;
    int temp;
    while(read<=numsSize-1)
    {
        if(nums[read] != 0)
        {
            temp = nums[read];
            nums[read] = nums[write];
            nums[write] = temp;

            write = write + 1;
            read = read + 1;
        }
        else if(nums[read] == 0)
        {
            read = read + 1;
        }
    }
}