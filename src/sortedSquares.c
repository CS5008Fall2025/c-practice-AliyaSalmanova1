#include <stdio.h>
#include <stdlib.h>

/**
* Name: Aliya Salmanova 
* Semester: Fall 2025
* I solved this myself. I got the logic quickly but it took a few tries to not have bugs. 
* I compared this with a standard solution afterwards and theirs is cleaner. I have more to learn. 
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int before0Arr[numsSize];
    int negCount = 0;

  //place numbers less than 0 in before0Arr starting from end to beginning
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            before0Arr[numsSize - 1 - negCount] = nums[i];
            negCount++;
        }
    }

    int i = 0;  
    int j = numsSize - negCount;
    int *arr = (int *)malloc(numsSize * sizeof(int));
    int counter = 0;

	//loop through before0Arr AND nums, placing the lower sqrt values first in arr
    while (i < numsSize || j < numsSize) {
        if (i < numsSize && nums[i] < 0) { 
            i++;
        } else if (i >= numsSize) {
            arr[counter++] = (int)((long long)before0Arr[j] * before0Arr[j]);
            j++;
        } else if (j >= numsSize) {
            arr[counter++] = (int)((long long)nums[i] * nums[i]);
            i++;
        } else if ((long long)before0Arr[j] * before0Arr[j] < (long long)nums[i] * nums[i]) {
            arr[counter++] = (int)((long long)before0Arr[j] * before0Arr[j]);
            j++;
        } else {
            arr[counter++] = (int)((long long)nums[i] * nums[i]);
            i++;
        }
    }

    *returnSize = numsSize;
    return arr;
}