#include <stdio.h>
#include <string.h>
#include "source/lista.h"

int main() {
    int v[] = {0,1,2,3};
    int ** p[10];

    *(p+0) = &v[1];

    printf("%d\n", **(p+0));

    return 0;
}
