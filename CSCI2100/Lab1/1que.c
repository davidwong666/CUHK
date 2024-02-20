/*
Time limit: 5000ms
Memory limit: 256mb

Description:
Given an integer array A and an integer number k, please perform a circular left shift on the array by k steps.

-----------------------Copy the following code, complete it and submit-----------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int circular_left_shift(int a[], int output[], int n, int k) {
  // WRITE YOUR CODE HERE
}

// DO NOT MODIFY THE CODE BELOW
int print_output(int output[], int n) {
  int i = 0;
  for (i = 0; i < n; i++) {
    printf("%d ", output[i]);
  }
  printf("\n");
  return 0;
}

int main() {
  int a[10240];
  int output[10240];
  int n, k, i;

  // read the input array and k
  scanf("%d", &n);
  scanf("%d", &k);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  // initialize the array output
  for (i = 0; i < n; i++) {
    output[i] = 0;
  }

  int res = circular_left_shift(a, output, n, k);
  print_output(output, n);
  return 0;
}



/*
-----------------------------------------End of Code-----------------------------------------

Input:
The first line contains two integers: N and k (k can be 0);
The second line contains a, an array of N integers, a_0, a_1, ..., a_(N-1);
0 <= N <= 10^3

Output:
The shifted array.

Sample Input 1:
4 3
1 2 3 4

The first shift: 	
2 3 4 1
The second shift: 	
3 4 1 2
The third shift: 	
4 1 2 3
Therefore, Sample Output 1:
4 1 2 3

Sample Input 2:
1 5   
100
Sample Output 2:
100

Sample Input 3:
3 0 
3 2 1
Sample Output 3:
3 2 1
*/