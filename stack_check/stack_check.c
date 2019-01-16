#include <stdio.h>

void * base;

void *base;
/* default stack size on Linux is 8 MiB, so fill 75% of it. */
//static const size_t stacksize = 6*1024*1024;
#define stacksize 64*1024

/* "clear" the stack by writing a sentinel value into it. */
void* stack_count_clear(void)
{
    const size_t asize = stacksize / sizeof(unsigned long);
    unsigned long stack[stacksize / sizeof(unsigned long)]; /* allocated on stack */
    unsigned long* p = stack;
    while ( p < stack + asize ) *p++ = 0xDEADC0DEu;
    return p;
}

/* checks the maximum usage of the stack since the last clear call. */
unsigned long stack_count_usage(void* lastbase)
{
    const size_t asize = stacksize / sizeof(unsigned long);
    unsigned long* p = (unsigned long*)lastbase - asize; /* calculate top of last clear */
    while ( *p == 0xDEADC0DEu ) ++p;
    return ((unsigned long*)lastbase - p) * sizeof(unsigned long);
}

unsigned long long factorial(int n)
{
    printf("maximum stack usage: %lld\n",
       (long long)stack_count_usage(base));

    if(n > 1)
        return n * factorial(n - 1);
    else
        return 1;

}

int main(int argc, char *argv[])
{

    unsigned long long fact;
    int n = 10;
    base = stack_count_clear();

    fact = factorial(n);

    printf("%d! = %llu\n", n, fact);

    return 0;
}