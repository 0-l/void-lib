#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"
#define PI (float) 3.14
#define len(x) (int) (sizeof(x) / sizeof(x[0]))
#define echo(f, ...) fprintf(stderr, "%s\n", f, ##__VA_ARGS__)
#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)
#define stralloc(str) (char*) malloc(strlen(str) + 1)
#define intalloc(num) (int*) malloc(sizeof(num))
#define new(obj) (obj*) malloc(sizeof(obj))
#define middle(x) (x[0] + (int) len(x)) / 2
#define for_each(iterator, array) \
    for (size_t iterator = 0; iterator < len(array); iterator++)
#define __assert(expr, action) do { \
        if (!(expr)) action;        \
    } while (0)                     \

typedef enum { true = 1, false = !true } bool;

void clear()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#else
    printf(COLOR_RED"Can't clear screen."COLOR_RESET);
#endif
}

unsigned long fib(unsigned long n) { return n <= 1 ? n : fib(n-1) + fib(n-2); }

unsigned long fact(unsigned long n) { return n <= 0 ? 1 : n * fact(n-1); }

int linear_search(int *a, int x)
{
    for (size_t i = 0; i < len(a) - 1; i++)
        return a[i] == x ? x : -1;
}

int binary_search(int *a, int x)
{
    int start = 0, end = len(a) - 1;

    while (start <= end) {
        int mid = middle(a);
        if (x == a[mid]) return mid;
        else if (x < a[mid]) end = mid - 1;
        else if (x > a[mid]) start = mid + 1;
        else return -1;
    }
}

// bubble sort = O(n)
int bsort(int *array)
{
    int temp;
    bool sorted;
    int *sort = (int*) malloc(len(array) * sizeof(int));
    while (true) {
        sorted = false;
        for (size_t i = 0; i < len(array) - 1; i++) {
            if (sort[i] > sort[i + 1]) {
                temp = sort[i];
                sort[i] = sort[i + 1];
                sort[i + 1] = temp;
                sorted = true;
            }
        }
        if (sorted == false)
            break;
    }
    for (size_t i = 0; i < len(array); printf("%d ", sort[i++]));
    free(sort);
    sort = NULL;
}

int32_t gcd(int u, int v)
{
    int t;
    while (u > 0) {
        if (u < v) { t = u; u = v; v = t; }
        u = u - v;
    }
    return v;
}

// quick sort O(n log n), worst case: O(n²)
void quicksort(int list[10], int left, int right)
{
    int pivot, temp, i, j, half;
    i = left;
    j = right;

    half = (int) ((i + j) / 2);
    pivot = list[half];

    do {
        while (list[i] < pivot) i = i + 1;
        while (list[j] > pivot) j = j - 1;

        if (i <= j) {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
            i = i + 1;
            j = j - 1;
        }
    } while (j > 1);

    if (left < j)
        quicksort(list, left, j);
    else if (i < right)
        quicksort(list, i, right);
}
