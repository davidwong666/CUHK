#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int circular_left_shift(int a[], int output[], int n, int k) {
  // WRITE YOUR CODE HERE
  if(k==0){
    for(int i=0; i<n; i++){
      output[i] = a[i];
    }
  }
  else{
    for(int i=0; i<k; i++){
      for(int j=0; j<n; j++){
        if(j+1<n){
          output[j]=a[j+1];
        }
        else{
          output[j]=a[n-1-j];
        }
      }
      for (int i=0; i<n; i++) {
        a[i] = output[i];
      }
    }
  }
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