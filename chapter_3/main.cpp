// main.cpp
#include <stdio.h>
#include <limits.h>
#include "common.h"

const int COE_COUNT = 15;
int coe[COE_COUNT+1] = {0,1,3,5,7,9,10,13,2,4,3,4,5,6,6,7}; 
int arr[COE_COUNT+1] = {1,0};

struct TaxInfo
{
    int begin;
    int end;
    int taxbase;
    double ratio;
};

double gettax(TaxInfo* ti, int size, int salary);
int test_gettax();
void test_linear_series();

double gettax(TaxInfo* ti, int size, int salary)
{
    if (!ti || size <= 0)
        return -1.0;
    int l = 0;
    int r = size - 1;
    int mid;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (ti[mid].begin >= salary)
            r = mid - 1;
        else if (ti[mid].end < salary)
            l = mid + 1;
        else
            return ti[mid].taxbase + (salary - ti[mid].begin) * ti[mid].ratio;
    }
    return -1.0;
}

int test_gettax()
{
    TaxInfo ti[] = {
        {0, 2199, 0, 0.0},
        {2200, 2699, 0, 0.14},
        {2700, 3199, 70, 0.15},
        {3200, 3699, 145, 0.16},
        {3700, 4199, 225, 0.17},
        {4200, 4699, 310, 0.19},
        {4700, 5199, 405, 0.21},
        {5200, 5699, 510, 0.24},
        {5700, INT_MAX, 630, 0.30}
    };
    int times = 3;
    int salary = 1345;
    for (int i = 0; i < times; ++i) {
        printf("salary:%d, tax:%lf\n", salary, gettax(ti, sizeof(ti)/sizeof(TaxInfo), salary));
        salary += 1000;
    }
    return 0;
}

void test_linear_series()
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
}

int main(int argc, char* argv[])
{
    test_gettax();
    return 0;
}

