#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) 
{
    *returnSize = 2;
    int *answer = malloc(sizeof(int) * 2);

    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                answer[0] = i;
                answer[1] = j;
                return answer;
            }
        }
    }
    return NULL;
}

int main()
{

    int nums[] = {3,3};
    int target = 6;
    int returnSize;

    int *answer = twoSum(nums, sizeof(nums)/sizeof(int), target, &returnSize);

    int targetAsnwer = nums[answer[0]] +  nums[answer[1]];

    printf("%d + %d = %d", nums[answer[0]], nums[answer[1]], targetAsnwer);
}