// main.cpp
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <utility>
#include <algorithm>
#include "common.h"


/**
 * @brief       Get the greatest common divisor of a and b
 * @paramiin]   a
 * @param[in]   b
 * @return
 *              !=0         succeed
 *              INT_MAX     failed
 **/
int gcd(int a, int b);

/**
 * @brief       Left shift vector of positions specified by @argv[cnt]
 * @param[in]   pointer of vector
 * @param[in]   vector size
 * @param[in]   shfit count
 * @return
 *              0       succeed
 *              -1      failed
 **/
int shift_left_acrobatic(int* a, int size, int cnt);

/**
 * @brief       Left shift vector of positions by multiple reverse
 * @param[in]   pointer of vector
 * @param[in]   vector size
 * @param[in]   shfit count
 * @return
 *              0       succeed
 *              -1      failed
 **/
int shift_left_by_multiple_reverse(int* a, int size, int cnt);

void test_gcd();
void test_shift_left();

int shift_left_acrobatic(int* a, int size, int cnt)
{
    if (!a || size <= 0 || cnt <= 0)
        return -1;
    cnt %= size;
    // Use the greatest common divisor as skip interval
    int gcd_ = gcd(size, cnt);
    int t,j,k;
    for (int i = 0; i < cnt; ++i) {
        t = a[i];
        j = i;
        for(;;) {
            k = (j + gcd_) % size;
            if (k == i)
                break;
            a[j] = a[k];
            j = k;
        }
        a[j] = t;
    }

    return 0;
}

int shift_left_by_multiple_reverse(int* a, int size, int cnt)
{
    if (!a || size <= 0 || cnt <= 0)
        return -1;
    cnt %= size;
    std::reverse(a, a + size);
    std::reverse(a, a + size - cnt);
    std::reverse(a + size - cnt, a + size);
    return 0;
}

// Get gcd by iterative division
int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return INT_MAX;
    if (b > a)
        std::swap(a, b);
    while (true) {
        int r = a % b;
        if (0 == r)
            return b;
        a = b;
        b = r;
    }
    // Shouldn't be here
    return INT_MAX;
}

void test_gcd()
{
    srand(time(NULL));
    int a = 0;
    int b = 0;
    for (int i = 0; i < 10; ++i) {
        a = rand() % 100 + 1;
        b = rand() % 100 + 1;
        printf("a = %d, b = %d, gcd = %d\n", a, b, gcd(a, b));
    }
}

void test_shift_left()
{
    int a[10] = {0};
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            a[j] = j + 1;
        }
        printf("shift left: %d, array is:\n", i+1);
        //shift_left_acrobatic(a, 10, i+1);
        shift_left_by_multiple_reverse(a, 10, i+1);
        print_array(a, 10);
    }
}

int main(int argc, char* argv[])
{
    //test_gcd();
    test_shift_left();
    return 0;
}
