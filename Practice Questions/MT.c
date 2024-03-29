/*MT is the short form of Mei Tuan in China.

Write a program that ouputs the total number of M & T in an input array with maximum modification of k times.
The first line of input contains a number n which is the size of the array. And a number k which is the maximum modification of the array.
The second line of input contains n numbers separated by a space.

*/
#include <stdio.h>

int main(){
    int n, k, count = 0;
    char c;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%c", &c);
        if(c == 'M' || c == 'T') count++;
        else if(k>0){
            count++;
            k--;
        }
    }

    printf("%d\n", count);
    return 0;
}