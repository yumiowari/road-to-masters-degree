#include <stdio.h>

#define n 100

int main(){
    int c1 = 0, c2 = 0;

    for(int i = 1; i <= n; i *= 2)
        for(int j = 1; j <= n; j++)
            c1++;

    for(int i = 1; i <= n; i *= 2)
        for(int j = 1; j <= i; j++)
            c2++;

    printf("%d - %d\n", c1, c2);
}