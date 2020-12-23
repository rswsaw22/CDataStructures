#include <stdio.h>
#include "vector.h"

int main(void) {
    printf("First practice at vector setup\n");
    printf("Let us do integers first!\n");

    printf("What first integer do you want in the array?\n");
    int first;
    scanf("%d", &first);

    printf("What is the second integer do you want in the array?\n");
    int second;
    scanf("%d", &second);

    printf("What is the third letter you want in the array?\n");
    int third;
    scanf("%d", &third);

    struct vec_t *myVector = Vector(sizeof(int), 3);

    PushBack((void *)&first, myVector);
    PushBack((void *)&second, myVector);
    PushBack((void *)&third, myVector);

    for (int i= 0; i < 3; i++) {
        printf("%d\n", *((int *)At(i, myVector)));
    }

    DestroyVector(myVector);

    return 0;
}