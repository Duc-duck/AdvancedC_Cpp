#include <stdio.h>
#include <stdarg.h>

#define tong(...) sum(__VA_ARGS__)

float sum(int count, ...){
    va_list va;

    float sum = 0.0;

    va_start(va, count);

    for (int i = 0; i < count; i++){
        sum+= va_arg(va, double);}

    va_end(va);

    return sum;
}

int main(int argc, char const *argv[])
{
    printf("tong %.1f\n", tong(6,2.1,3.5,4.4,5.3,6.9,10.38));
    return 0;
}