#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_LEN 1024
#define INT_MIN -2147483648

int num_subarrays_product_between_L_and_R(int* nums, int numsSize, int L, int R) {
    // WRITE YOUR CODE HERE
    int count = 0;
    
    for (int left = 0; left < numsSize; left++) {
        int product = 1;
        
        for (int right = left; right < numsSize; right++) {
            product *= nums[right];
            
            if (product > R) {
                break;
            }
            
            if (product > L && product < R) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int L = 10;
    int R = 100;

    int size_nums;
    
    scanf("%d", &size_nums);
    scanf("%d", &L);
    scanf("%d", &R);

    int nums[size_nums];

    for (int i = 0; i < size_nums; i++) {
        scanf("%d", &nums[i]);
    }
    
    int result = num_subarrays_product_between_L_and_R(nums, size_nums, L, R);
    printf("%d\n", result);

    return 0;
}