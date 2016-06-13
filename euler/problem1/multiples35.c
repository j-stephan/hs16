#include <stdio.h>
#include <time.h>

int main()
{
    struct timespec start, end;

    clock_gettime(CLOCK_MONOTONIC, &start);

    int sum = 0;
    for(int i = 0; i < 1000; ++i)
    {
        if((i % 3 == 0) || (i % 5 == 0))
            sum += i;
    }
    
    clock_gettime(CLOCK_MONOTONIC, &end);

    printf("Sum: %i\n", sum);
    printf("Elapsed time: %lins\n", end.tv_nsec - start.tv_nsec);
    return 0;
}
