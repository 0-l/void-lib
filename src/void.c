#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
#define for_each(iterator, array) \
    for (size_t iterator = 0; iterator < len(array); iterator++)

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

