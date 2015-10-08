// main.cpp
#include <stdio.h>
#include "common.h"

const int COE_COUNT = 15;
int coe[COE_COUNT+1] = {0,1,3,5,7,9,10,13,2,4,3,4,5,6,6,7}; 
int arr[COE_COUNT+1] = {1,0};

int main(int argc, char* argv[])
{
    int m = 10;
    for (int i = 1; i <= 10; ++i) {
        int j = i;
        int k = 1;
        while (j > 0) {
            arr[i] += coe[k++] * arr[--j];
        }
    }
    printf("the array is:\n");
    print_array(arr+1, COE_COUNT);
    return 0;
}

