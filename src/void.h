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
#define PI (float) 3.14159265
#define len(x) (int)(sizeof(x) / sizeof(x[0]))
#define echo(f, ...) fprintf(stderr, "%s\n", f, ##__VA_ARGS__)
#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)
#define stralloc(str) (char*)malloc(strlen(str) + 1)
#define intalloc(num) (int*)malloc(sizeof(num))
#define new(obj) (obj*)malloc(sizeof(obj))
#define middle(x) (x[0] + (int)len(x)) / 2
#define for_each(iterator, array) \
    for (size_t iterator = 0; iterator < len(array); iterator++)
#define __assert(expr, action) do { \
        if (!(expr)) action;        \
    } while (0)
#define Copy(in, ...) (in).copy((in), __VA_ARGS__)
#define Free(in, ...) (in).free((in), __VA_ARGS__)
#define is_even(num) return ((num & 0x1) < 1) ? 1 : 0
#define is_odd(num)  return (!(is_even(num))) ? 1 : 0
#define loop for (;;)
#define str(name) #name
#define lambda(return_type, ...) \
  __extension__ \
  ({ \
    return_type __fn__ __VA_ARGS__ \
    __fn__; \
  })
#define container_of(ptr, type, member) ({                  \
    const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
        (type *)( (char *)__mptr - offsetof(type,member) ); })
#define is_array(a) ((void *)&a == (void *)a)
#define cat(arg, ...) arg##__VA_ARGS__
#define swap(x,y) do \
   { unsigned char swap_temp[sizeof(x) == sizeof(y) ? (signed)sizeof(x) : -1]; \
     memcpy(swap_temp,&y,sizeof(x)); \
     memcpy(&y,&x,       sizeof(x)); \
     memcpy(&x,swap_temp,sizeof(x)); \
    } while(0)

#if defined NDEBUG
    #define TRACE(format, ...)
#else
    #define TRACE(format, ...) printf("%s::%s(%d)" format, __FILE__, __FUNCTION__,  __LINE__, __VA_ARGS__)
#endif

typedef enum { true = 1, false = !true } bool;

typedef int8_t    i8;
typedef uint8_t   u8;
typedef int16_t  i16;
typedef uint16_t u16;
typedef int32_t  i32;
typedef uint32_t u32;
typedef int64_t  i64;
typedef uint64_t u64;

i32 sys(const char *str) { system(str); }

void xor_swap(int* a, int* b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

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

unsigned long fib(unsigned long n)  { return n <= 1 ? n : fib(n-1) + fib(n-2); }
unsigned long fact(unsigned long n) { return n <= 0 ? 1 : n * fact(n-1); }

int lsearch(int *a, int x)
{
    for (size_t i = 0; i < len(a) - 1; i++)
        return a[i] == x ? x : -1;
}

i32 gcd(int u, int v)
{
    int t;
    while (u > 0) {
        if (u < v) { t = u; u = v; v = t; }
        u = u - v;
    }
    return v;
}

float quicksort(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    y  = * (long *) &y;
    i  = 0x5f3759df - (i >> 1);
    y  = * (float *) &i;
    y  = y * (threehalfs - (x2 * y * y));
    return y;
}
