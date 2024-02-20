#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findValleyIndex(int arr[], int n) {
	// WRITE YOUR CODE HERE
	if(n==1) return 0;
	if(n>1){
		if(arr[0]<arr[1]) return 0;
		if(arr[n-1]<arr[n-2]) return n-1;
	}

	int left = 0;
	int right = n - 1;

	while (left < right) {
    	int mid = left + (right - left) / 2;

    	if (arr[mid] < arr[mid + 1]) {
        	right = mid;
    	}
		else {
    		left = mid + 1;
    	}
	}
	return left;
}

int main(int argc, char *argv[]) {
	

	int N;
	scanf("%d", &N);
	
	int nums[N];
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &nums[i]);
	}
	
	int index;
	
	for(int i = 0; i < 50; i++){
		index = findValleyIndex(nums, N);
	}
	printf("%d", index);
	
}
