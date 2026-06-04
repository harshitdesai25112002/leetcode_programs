/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {

    *returnSize = 2;

    int *answer = (int *)malloc(2 * sizeof(int));

    int left = 0;
    int right = numbersSize - 1;

    while (left < right)
    {
        int sum = numbers[left] + numbers[right];

        if (sum == target)
        {
            answer[0] = left + 1;
            answer[1] = right + 1;
            return answer;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return answer;
}